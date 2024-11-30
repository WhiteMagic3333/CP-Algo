<?php

namespace Internshala\Helpers\Search_Page\Seo;

use Doctrine\ORM\EntityManager;
use Internshala\Helpers\CommonFunctions;
use Internshala\Helpers\CommonValues;

class Seo {

    private $category_regex_patterns = [
        '%28' => '(\(|%28)',
        '%29' => '(\)|%29)',
        '%2F' => '(\/|%2F|%2f)',
        '%20' => '(%20| |-)',
    ];

    private $category_regex_values = [
        '%28' => '(',
        '%29' => ')',
        '%20' => '-',
    ];

    public function seo(EntityManager $em, array $data): array {
        $query = $data['query'] ?? [];
        $results_metadata = $data['results_metadata'] ?? [];
        $internships_meta = $data['internships_meta'] ?? [];
        $filters_count = (int)$data['filters_count'] ?? [];
        $internships_meta_count = $results_metadata['internshipsMetaCount'] ?? 0;
        if ($query['fresher_job_checked']) {
            $seo_job = new Seo_Job($em);
            $seo = $seo_job->seo_fresher_job($query, $results_metadata);
            $seo_faq = $seo_job->seo_fresher_job_faq($query);
            $seo_breadcrumb = $seo_job->seo_job_breadcrumbs($query, $filters_count, 'fresher_job');
        } else if ($query['employment_type'] == 'job') {
            $seo_job = new Seo_Job($em);
            $seo = $seo_job->seo_job($query, $results_metadata);
            $seo_faq = $seo_job->seo_job_faq($query);
            $seo_breadcrumb = $seo_job->seo_job_breadcrumbs($query, $filters_count, 'job');
        } else {
            $seo_internship = new Seo_Internship($em);
            $seo = $seo_internship->seo_internship($query, $results_metadata);
            $seo_faq = $seo_internship->seo_internship_faq($query);
            $seo_breadcrumb = $seo_internship->seo_internship_breadcrumbs($query, $filters_count);
        }
        // $seo_override = new Seo_Override();
        // $seo = $seo_override->override_meta_details($em, $seo, $results_metadata);

        $seo = array_merge($seo, $this->compute_main_url_for_canonical_tag($query));
        $seo = array_merge($seo, ['faqs' => $seo_faq]);
        $seo = array_merge($seo, $this->create_structured_data_for_faq($seo_faq));
        $seo = array_merge($seo, ['breadcrumbs' => $seo_breadcrumb]);
        $seo = array_merge($seo, $this->create_structured_data_for_breadcrumbs($seo_breadcrumb));
        $seo = array_merge($seo, $this->create_structured_data_for_item_list($internships_meta, $seo_breadcrumb, $internships_meta_count));
        return $seo;
    }

    private function create_structured_data_for_faq(array $faq_array): array {
        $mainEntity_array = [];
        foreach ($faq_array as $faq) {
            $mainEntity_array[] = [
                '@type' => 'Question',
                'name' => $faq['question'],
                'acceptedAnswer' => [
                    '@type' => 'Answer',
                    'text' => $faq['answer']
                ],
            ];
        }
        $rich_text_faq = [
            '@context' => 'http://schema.org',
            '@type' => 'FAQPage',
            'mainEntity' => $mainEntity_array,
        ];
        return ['rich_text_faq' => $rich_text_faq];
    }

    private function compute_main_url_for_canonical_tag(array $query): array {
        $cf = CommonFunctions::instance();
        $page_url = $cf->getCurrentUrl();
        $pos = strpos($page_url, '%3F');
        if ($pos) {
            $encoded_params_string = substr($page_url, $pos);
            $slash_pos = strpos($encoded_params_string, '/');
            $slash_str = $slash_pos > 0 ? substr($encoded_params_string, $slash_pos) : '';
            $encoded_params_string = str_replace($slash_str, '', $encoded_params_string);
            $page_url = preg_replace("/$encoded_params_string/", '', $page_url);
        }
        $work_from_home = $query['workFromHome'] ?? false;
        $remote_job = $query['remote_job'] ?? false;
        $job_internship_checked = $query['job_internship_checked'] ?? false;
        $category_names = $query['categories_name'] ? $query['categories_name'] : null;
        if ($work_from_home && $query['employment_type'] == 'internship' && preg_match('/-jobs(-)?/', $page_url)) {
            return [
                'canonical_url' => base_url(preg_replace('/-jobs(-)?/', '-internships$1', $page_url)),
            ];
        } else {
            $page_url = $this->match_and_replace_arguments_part_in_url($page_url);
            // if (isset($category_names) && $category_names) {
            //     $page_url = $this->match_and_replace_categories_part_in_url($page_url);
            // }
            if ($job_internship_checked && $remote_job && $query['employment_type'] == 'job') {
                $page_url = '/jobs/work-from-home/';
            }
            return [
                'canonical_url' => base_url(rtrim($page_url, '/') . '/'),
            ];
        }
    }

    private function match_and_replace_arguments_part_in_url(string $page_url): string {
        $page_url_array = explode('/', $page_url);
        $seo_page_url = [];
        foreach ($page_url_array as $path_value) {
            $path_value = rawurldecode($path_value);
            $path_value = CommonFunctions::make_string_seo_friendly($path_value);
            $seo_page_url[] = $path_value;
        }
        $page_url = implode('/', $seo_page_url);
        return $page_url;
    } 

    private function match_and_replace_categories_part_in_url(string $page_url, array $categories): string {
        $category_replacement_array = [];
        $category_pattern_array = [];
        foreach ($categories as $category) {
            $category = rawurlencode($category);
            $category_value = strtolower($category);
            foreach ($this->category_regex_values as $value_match => $value_replace) {
                $category_value = str_replace($value_match, $value_replace, $category_value);//creating replacement value
            }
            $category_replacement_array[] = $category_value;

            foreach ($this->category_regex_patterns as $pattern_match => $pattern_replace) {
                $category = str_replace($pattern_match, $pattern_replace, $category);//creating regex pattern
            }
            $category_pattern_array[] = $category;
        }
        $category_replacement = implode(',', $category_replacement_array);
        $category_pattern = '/' . implode('(%2C|,)', $category_pattern_array) . '/i';

        $page_url = preg_replace($category_pattern, $category_replacement, $page_url);
        $page_url = preg_replace('/%2C/', ',', $page_url);

        return $page_url;
    }

    private function create_structured_data_for_breadcrumbs(array $breadcrumb_array): array {
        if (empty($breadcrumb_array)) {
            return [];
        }
        $mainEntity_array = [];
        $position = 1;
        foreach ($breadcrumb_array as $breadcrumb) {
            $mainEntity_array[] = [
                '@type' => 'ListItem',
                'position' => $position++,
                'name' => $breadcrumb['name'],
                'item' => $breadcrumb['item'],
            ];
        }
        $rich_text_breadcrumb = [
            '@context' => 'http://schema.org',
            '@type' => 'BreadcrumbList',
            'itemListElement' => $mainEntity_array,
        ];
        return ['rich_text_breadcrumb' => $rich_text_breadcrumb];
    }

    private function create_structured_data_for_item_list(array $listings, array $seo_breadcrumb, int $internships_meta_count): array {
        if (empty($listings)) {
            return [];
        }
        $currnet_page = end($seo_breadcrumb);
        $main_entity_array = [];
        $position = 1;
        foreach ($listings as $meta) {
            $main_entity_array[] = [
                '@type' => 'ListItem',
                'position' => $position++,
                'name' => $meta['title'],
                'url' => base_url("{$meta['employment_type']}/detail/{$meta['url']}"),
            ];
        }
        $rich_text = [
            '@context' => 'http://schema.org',
            '@type' => 'ItemList',
            'url' => $currnet_page['item'] ?? base_url(),
            'name' => $currnet_page['name'] ?? 'Internshala',
            'numberOfItems' => $internships_meta_count ?? 0,
            'itemListElement' => $main_entity_array,
        ];
        return ['rich_text_item_list' => $rich_text];
    }

    public function seo_directories_meta_data(string $employment_type, string $type): array {
        if ($employment_type == 'job') {
            $meta_data = Seo_Job::$seo_directories_job_meta_data[$type];
        } else {
            $meta_data = Seo_Internship::$seo_directories_internship_meta_data[$type];
        }
        return $meta_data;
    }
}
