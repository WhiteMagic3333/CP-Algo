<?php

namespace Internshala\Helpers\Search_Page\Seo;

use Internshala\Helpers\CommonFunctions as cf;
use Internshala\Helpers\CommonValues;

class Seo_Internship {

    private $em;

    public static $seo_directories_internship_meta_data = [
        'category' => [
            'title' => 'Search Internships by Category on Internshala',
            'description' => 'Browse the list of various internships by category on Internshala to find the most relevant internship in your desired stream. Register for free and apply today!'
        ],
        'location' => [
            'title' => 'Search Internships by Location on Internshala',
            'description' => 'Browse the list of various internships by location on Internshala to find the most relevant internship in your desired location. Register for free and apply today!'
        ],
    ];
    public function __construct($em) {
        $this->em = $em;
    }

    public function seo_internship(array $query, array $results_metadata): array {

        $title = 'Internship | Summer Internship ' . date('Y') . ' | Internship in India';
        $meta_description = 'Apply to 2000+ summer internships all over India and abroad with stipend across all streams. Apply and register for free now.';

        $internshipsCount = isset($results_metadata['internshipsMetaCount']) ? $results_metadata['internshipsMetaCount'] : "";

        $keywords = $query['keywords'] ? $query['keywords'] : NULL;
        $category_name = $query['categories_name'] ? $query['categories_name'][0] : NULL;
        $categories_count = isset($query['categories_name']) ? count($query['categories_name']) : 0;

        $location_name = $query['locations_name'] ? $query['locations_name'][0] : NULL;
        $locations_count = $query['locations_name'] ? count($query['locations_name']) : 0;

        $company_name = $query['company_name'] ? $query['company_name'] : '';
        $wfh = $query['workFromHome'];
        $stipend = $query['onlyStipend'];
        $part_time = $query['part_time'];
        $segment = $query['segment'];
        $matching_preference = $query['matching_preference'] ? $query['matching_preference'] : FALSE;
        $ppo_checked = $query['to_show_ppo_checkbox'] ?? FALSE;

        if ($keywords) {
            if ($keywords === "marketing") {
                $title = 'Marketing Internship | Internshala';
                $meta_description = 'Find the best summer internships in ' . date('Y') . ' for marketing students in Bangalore, Mumbai & major cities in India with attractive stipends. Apply for free now.';
            } else if ($keywords === "economics") {
                $title = 'Economics Internship | Internshala';
                $meta_description = 'Find the best summer internships for economics students in India with attractive stipends in ' . date('Y') . '. Apply for free now.';
            } else if ($keywords === "content writing") {
                $title = 'Content Writing Internship | Internshala';
                $meta_description = 'Find the best content writing internships for students with attractive stipends in ' . date('Y') . '. Work from home internship in content writing also available. Apply now.';
            } else {
                $title = 'Internship, Summer Internship, Internship in India | Internshala';
                $meta_description = 'Internships, Summer Internships, Summer Trainings for students in India. Internships & Trainings for Engineering, MBA, Law, Media, Arts, Science, Commerce students';
            }
        }


        $criteria_count = 0;
        if ($wfh) {
            $criteria_count++;
            $work_from_home_to_display = 'Work From Home ';
            $title = 'Work From Home Internships | Online Internships';
            $meta_description = 'Are you looking for online internships or work from home internships in ' . date('Y') . '? Find 1,500+ online internships with stipend. Apply now and earn by working from home.';
        } else {
            $work_from_home_to_display = "";
        }
        if ($part_time) {
            $criteria_count++;
            $title = 'Part Time Jobs | Part Time Jobs for Students | Internshala';
            $meta_description = 'Are you looking for a part time job/internship? Find 2,500+ part time jobs/internships in various fields in your preferred location in ' . date('Y') . '. Apply for free now.';
        }

        if ($segment == "summer") {
            $criteria_count++;
            $segment_to_display = "Summer ";
            $title = 'Summer Internships | Internshala';
            $meta_description = 'Find and apply to hundreds of summer internships in ' . date('Y') . ' with attractive stipends for students from various streams in India.';
        } else {
            $segment_to_display = "";
        }


        if ($stipend) {
            $criteria_count++;
            $stipend_to_display = "Paid ";
            $title = 'Paid Internship | Paid Internships in India';
            $meta_description = 'Find and apply to hundreds of paid internships with attractive stipends with top brands for students of various streams in India.';
        } else {
            $stipend_to_display = "";
        }

        if ($category_name != '') {
            $criteria_count++;
            $category_name_to_display = $category_name . " ";
            $title = $category_name . ' Internship | Internshala';
            $meta_description = 'Find best ' . $category_name . ' internships at leading companies in India and abroad for summer ' . date('Y') . '. Apply now for free.';
        } else {
            $category_name_to_display = "";
        }

        if ($location_name != '') {
            $criteria_count++;
            $location_name_to_display = "in " . $location_name . " ";
            $title = 'Internship in ' . $location_name . ' | Internshala';
            $meta_description = 'Find the best paid summer internships in ' . $location_name . ' from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
        } else {
            $location_name_to_display = "";
        }

        if ($company_name != '') {
            $criteria_count++;
            $company_name_to_display = "at " . $company_name;
            $title = $company_name . ' Internship | Internshala';
            $meta_description = 'Find the latest internships at ' . $company_name . ' for summer ' . date('Y') . '. Apply for free now.';
        } else {
            $company_name_to_display = "";
        }

        if ($ppo_checked) {
            $criteria_count++;
            $title = 'Internship with job offer | Internshala';
            $meta_description = 'Find the best paid summer internships with job offer at leading companies in India. Apply for free now. ';
        }

        $common_content_to_display = trim($work_from_home_to_display . $stipend_to_display . $category_name_to_display . $segment_to_display . "Internship " . $location_name_to_display . $company_name_to_display);

        if ($criteria_count > 1) {
            $title = $common_content_to_display . ' | Internshala';
            $meta_description = 'Find best ' . $common_content_to_display . ' for summer ' . date('Y') . '. Apply now for free';
        }

        if ($category_name != '' && strtolower($category_name) == 'chartered accountancy (ca)') {
            $category_name_to_display = "Chartered Accountancy (CA) Articleships";
            $title = 'Chartered Accountancy (CA) Articleships | Internshala';
            $meta_description = 'Find best Chartered Accountancy (CA) Articleships at leading companies in India and abroad for summer ' . date('Y') . '. Apply now for free.';

            $common_content_to_display = trim($work_from_home_to_display . $stipend_to_display . $category_name_to_display . " " . $location_name_to_display . $company_name_to_display);

            if ($criteria_count > 1) {
                $title = $common_content_to_display . ' | Internshala';
                $meta_description = 'Find best ' . $common_content_to_display . ' for summer ' . date('Y') . '. Apply now for free';
            }
        }

        if ($part_time && $locations_count == 1 && $location_name && $criteria_count == 2) {
            $criteria_count++;
            $location_name_to_display = "in " . $location_name;
            $title = 'Part Time Jobs ' . $location_name_to_display . ' | Internshala';
            $meta_description = 'Find the best part time jobs/internships ' . $location_name_to_display . ' from top companies in various fields in ' . date('Y') . '. Earn while working part time. Apply for free now.';
            if ($location_name === 'jamshedpur') {
                $title = 'Part Time Jobs in Jamshedpur | Internshala';
            } else if ($location_name === 'allahabad') {
                $title = 'Part Time Jobs in Allahabad  | Internshala';
            } else if ($location_name === 'gwalior') {
                $title = 'Part Time Jobs in Gwalior | Internshala';
            } else if ($location_name === 'meerut') {
                $title = 'Part Time Jobs in Meerut | Internshala';
            } else if ($location_name === 'varanasi') {
                $title = 'Part Time Jobs in Varanasi | Internshala';
            } else if ($location_name === 'guwahati') {
                $title = 'Part Time Jobs in Guwahati | Internshala';
            } else if ($location_name === 'vizag') {
                $title = 'Part Time Jobs in Vizag | Internshala';
            } else if ($location_name === 'ranchi') {
                $title = 'Part Time Jobs in Ranchi | Internshala';
            } else if ($location_name === 'patna') {
                $title = 'Part Time Jobs in Patna | Internshala';
            } else if ($location_name === 'bhubaneswar') {
                $title = 'Part Time Jobs in Bhubaneswar | Internshala';
            } else if ($location_name === 'cuttack') {
                $title = 'Part Time Jobs in Cuttack | Internshala';
            } else if ($location_name === 'nagpur') {
                $title = 'Part Time Jobs in Nagpur | Internshala';
            } else if ($location_name === 'lucknow') {
                $title = 'Part Time Jobs in Lucknow | Internshala';
            } else if ($location_name === 'jabalpur') {
                $title = 'Part Time Jobs in Jabalpur | Internshala';
            }
        }

        if ($part_time && $categories_count == 1 && $category_name && $criteria_count == 2) {
            $criteria_count++;
            $title = 'Part Time ' . $category_name_to_display . 'Jobs | Internshala';
            $meta_description = 'Find the best part time ' . strtolower($category_name_to_display) . 'jobs/internships in ' . date('Y') . ' in top companies. Apply for free now.';
        }

        if ($part_time && $categories_count == 1 && $locations_count == 1 && $location_name && $category_name_to_display && $criteria_count == 3) {
            $criteria_count++;
            $location_name_to_display = "in " . $location_name;
            $title = 'Part Time ' . $category_name_to_display . 'Jobs ' . $location_name_to_display;
            $meta_description = "Find the best part time " . strtolower($category_name_to_display) . "jobs/internships " . $location_name_to_display . " in " . date('Y') . " in top companies. Apply for free now.";
        }

        if ($wfh && $locations_count == 1 && $location_name && $criteria_count == 2) {
            $criteria_count++;
            $location_name_to_display = "in " . $location_name;
            $title = 'Work From Home Internships ' . $location_name_to_display . ' | Online Internships';
            $meta_description = 'Find the best online internships or work from home internships ' . $location_name_to_display . ' from top companies in ' . date('Y') . '. Apply now for free.';

            $selected_locations = array('jalandhar', 'udaipur', 'agra', 'kanpur', 'nashik', 'guwahati', 'raipur', 'visakhapatnam', 'dehradun', 'ranchi', 'surat', 'ludhiana', 'patna', 'vadodara', 'kochi', 'bhubaneswar', 'coimbatore', 'nagpur', 'mohali', 'bhopal', 'jaipur');

            if (in_array(strtolower($location_name), $selected_locations)) {
                $title = "Work From Home Internships in $location_name | Online Internships";
                //$heading = "1575 Online jobs/internships in $location_name";
            }
        }

        if ($wfh && $categories_count == 1 && $category_name_to_display && $criteria_count == 2) {
            $criteria_count++;
            $title = "Work From Home $category_name_to_display Internships | Online Internships";
            $meta_description = 'Find the best work from home ' . strtolower($category_name_to_display) . ' internships at top companies in ' . date('Y') . '. Apply now for free.';
        }

        if ($wfh && $categories_count == 1 && $locations_count == 1 && $location_name && $category_name_to_display && $criteria_count == 3) {
            $criteria_count++;
            $location_name_to_display = "in " . $location_name;
            $title = 'Work From Home ' . $category_name_to_display . 'Internships ' . $location_name_to_display;
            $meta_description = 'Find the best work from home ' . strtolower($category_name_to_display) . 'internships ' . $location_name_to_display . ' at top companies in ' . date('Y') . '. Apply for free now.';
        }

        if ($ppo_checked && $categories_count == 1 && $category_name_to_display && $criteria_count == 2) {
            $criteria_count++;
            $title = $category_name_to_display . ' internship with job offer';
            $meta_description = 'Find best ' . strtolower($category_name_to_display) . 'internships with job offers at leading companies in India for summer ' . date('Y') . '. Apply now for free.';
        }

        if ($ppo_checked && $locations_count == 1 && $location_name && $criteria_count == 2) {
            $criteria_count++;
            $location_name_to_display = "in " . $location_name;
            $title = 'Internship with job offer ' . $location_name_to_display;
            $meta_description = 'Find the best paid summer internships with job offer ' . $location_name_to_display . ' from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
        }
        if ($ppo_checked && $categories_count == 1 && $locations_count == 1 && $location_name && $category_name_to_display && $criteria_count == 3) {
            $criteria_count++;
            $location_name_to_display = "in " . $location_name;
            $title = $category_name_to_display . 'internship ' . $location_name_to_display . ' with job offer';
            $meta_description = 'Find best ' . strtolower($category_name_to_display) . 'internships with job offer ' . $location_name_to_display . '. Apply for free now.';
        }

        if ($matching_preference) {
            $title = 'Internships matching your Preferences';
            $meta_description = 'Internships matching your Preferences';
        } else if ($category_name == "NGO") {
            $title = 'Volunteer in India | NGO Internship | Internshala';
        } else if ($wfh && $category_name == "MBA") {
            $title = "Live Projects for MBA | Virtual MBA Internship | Internshala";
            $meta_description = "Are you looking for live projects in management in " . date('Y') . "? Find 300+ such internships/live projects that too with stipend. View now.";
        }

        if ($categories_count == 1 && $category_name && $criteria_count == 1) {
            $category_name = strtolower($category_name);
            if ($category_name === 'international') {
                $title = 'International Internships | Foreign Internships for Indian Students';
                $meta_description = 'Find 100s of international internships for Indian students of engineering & other degrees in Germany, USA, Australia & other major countries in the world in ' . date('Y') . '.';
            } else if ($category_name === 'engineering') {
                $title = 'Internship for Engineering Students | Engineering Internship';
                $meta_description = 'Find the best summer internships in ' . date('Y') . ' for engineering students in all the major cities in India with attractive stipends. Apply for free now.';
            } else if ($category_name === 'science') {
                $title = 'Science internship | Internshala';
                $meta_description = 'Apply to hundreds of prestigious research internships in science, mathematics, physics, chemistry, and biology for students in India in ' . date('Y') . '.';
            } else if ($category_name === 'mba') {
                $title = 'MBA Internship | Summer Internship for MBA students |Internshala';
                $meta_description = 'Find the best summer internships in ' . date('Y') . ' for MBA students with attractive stipends in Bangalore, Hyderabad, Delhi & other major cities in India. Apply for free now.';
            } else if ($category_name === 'media') {
                $title = 'Media Internship| Internship in Media | Internshala';
                $meta_description = 'Find the best media internships, journalism and photography internships with attractive stipends for students all over India in ' . date('Y') . '. Apply for free now.';
            } else if ($category_name === 'law') {
                $title = 'Law Internship | Law Internship in Delhi | Internshala';
                $meta_description = 'Find the best legal internships at reputed law firms in Delhi, Mumbai, Bangalore & major cities in India in ' . date('Y') . ' with attractive stipends. Apply for free now.';
            } else if ($category_name === 'design') {
                $title = 'Graphic Design Internships | Internshala';
                $meta_description = 'Find the best summer internships for design students in Delhi, Mumbai & other major cities in India with attractive stipends in ' . date('Y') . '. Apply for free now.';
            } else if ($category_name === 'other') {
                $title = 'Public Policy, Content, Editorial, Cartoonist Internships | Internshala';
                //$meta_description = '';
            } else if ($category_name === 'architecture') {
                $title = 'Architecture Internship | Internshala';
                $meta_description = 'Apply to the best architecture internships in ' . date('Y') . ' with leading architects & architectural firms in Delhi, Bangalore, Mumbai, Hyderabad, Pune, Chennai & other cities in India.';
            } else if ($category_name === 'iit') {
                $title = ' IIT Summer Internship ' . date('Y') . ' | IIT Internship';
                $meta_description = 'Apply to latest summer internships in ' . date('Y') . ' at IIT Madras, IIT Delhi, IIT Kanpur, IIT Bombay, IIT Roorkee, IIT Kharagpur, IIT Jodhpur and other IITs';
            } else if ($category_name === 'summer research fellowship') {
                $title = 'IISc Internship | Summer Fellowship ' . date('Y') . ' | Internshala';
                $meta_description = 'Find the best summer research fellowships & internships at IISc, IAS, JNCASR, TIFR, IISER & other top institutes in ' . date('Y') . '. Apply for free now.';
            } else if ($category_name === 'market/business research') {
                $title = 'Market Research Internship | Internshala';
                $meta_description = 'Find the best market-business research internships for students in ' . date('Y') . ' with attractive stipends. Apply for free now.';
            } else if ($category_name === "computer science") {
                $title = 'Internship for CSE students | Computer Science Internships |Internshala';
                $meta_description = 'Find and apply for CSE internships for students in 1st, 2nd, 3rd and 4th years of study and graduates all over India. Apply for free and earn attractive stipends.';
            } else if ($category_name === "electronics") {
                $title = 'Internship for ECE Students | Electronics Internship | Internshala';
                $meta_description = 'Find the best summer internships in ' . date('Y') . ' for Electronics/Electrical Engineering students in core companies with attractive stipends. Apply for free today!';
            } else if ($category_name === "mechanical") {
                $title = 'Mechanical Engineering Internships | Internshala';
                $meta_description = 'Find the best mechanical engineering internships & summer trainings with attractive stipends for students in India in ' . date('Y') . '. Apply for free now.';
            } else if ($category_name === "civil") {
                $title = 'Civil Engineering Internships | Internshala';
                $meta_description = 'Find the best summer internships in India for civil engineering students in ' . date('Y') . ' with attractive stipends. Apply for free now.';
            } else if ($category_name === "finance") {
                $title = 'Finance Internship | Internshala';
                $meta_description = 'Find the best summer internships in ' . date('Y') . ' for finance students in Delhi, Mumbai, Bangalore & major cities in India with attractive stipends. Apply for free now.';
            } else if ($category_name === "chemical") {
                $title = 'Chemical Engineering Internships | Internship for Chemical Engineering Students ' . date('Y') . '';
                $meta_description = 'Find the best summer internships in India for chemical engineering students in ' . date('Y') . ' with attractive stipends. Apply for free now.';
            } else if ($category_name === "chartered accountancy (ca)") {
                $title = 'CA Articleship | Internshala';
                $meta_description = "Find the best CA articleships at firms in India in the field of Finance, Accounting, Taxation, and Auditing with exciting stipends. Apply now for free.";
            } else if ($category_name === "company secretary (cs)") {
                $title = 'CS Internship | Internshala';
            } else if (strtolower($category_name) === "ngo") {
                $meta_description = "Are you looking for NGO internships? Find 100+ volunteering opportunities at top NGOs and give back to the community. View now.";
            } else if (strtolower($category_name) === "campus ambassador") {
                $title = 'Campus Ambassador Program | Internshala';
            }
        }

        if ($segment == "internship_for_women") {
            $title = "Internship Jobs For Women | Work From Home Options | Full Time";
            $meta_description = "An Internshala initiative, “Internships For Women”, brings 5000+ paid internship jobs for women. All women including housewife & mother can easily find work now.";
        }


        if ($segment == "internship_for_women") {
        } else if (strtolower($company_name) == "reserve bank of india (rbi)" && $criteria_count == 1) {
            $meta_description = "Find internships currently being offered by Reserve Bank of India (RBI). Apply online for free.";
        } else if ($locations_count == 1 && $location_name && $criteria_count == 1) {
            $location_name = strtolower($location_name);
            if ($location_name === "delhi") {
                $title = 'Internship in Delhi | Internshala';
                $meta_description = 'Find the best paid summer internships in Delhi from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
            } else if ($location_name === 'bangalore') {
                $title = 'Internship in Bengaluru | Internship | Internshala';
                $meta_description = 'Find the best paid summer internships in Bangalore from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
            } else if ($location_name === 'hyderabad') {
                $title = 'Internship in Hyderabad | Internshala';
                $meta_description = 'Find the best paid summer internships in Hyderabad from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
            } else if ($location_name === 'mumbai') {
                $title = 'Internship in Mumbai | Internshala';
                $meta_description = 'Find the best paid summer internships in Mumbai from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
            } else if ($location_name === 'chennai') {
                $title = 'Internship in Chennai | Internship | Internshala';
                $meta_description = 'Find the best paid summer internships in Chennai from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
            } else if ($location_name === 'pune') {
                $title = 'Internship in Pune | Internshala';
                $meta_description = 'Find the best paid summer internships in Pune from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
            } else if ($location_name === 'kolkata') {
                $title = 'Internship in Kolkata | Internshala';
                $meta_description = 'Find the best paid summer internships in Kolkata from top companies in engineering, MBA and other streams in ' . date('Y') . '. Apply for free now.';
            } else if ($location_name === 'bhopal') {
                $title = 'Bhopal Internship | Internship in Bhopal - Internshala';
            } else if ($location_name === 'chandigarh') {
                $title = 'Chandigarh Internship | Internship in Chandigarh - Internshala';
            } else if ($location_name === 'mohali') {
                $title = 'Internships in Mohali | Internshala';
            }else if ($location_name === 'allahabad') {
                $title = 'Internship Jobs in Allahabad | Internshala';
            }else if (in_array($location_name, ['agra','cuttack','mathura','sonipat','kanpur','udaipur','vijayawada', 'varanasi', 'jalandhar','panipat','ahmedabad','jaipur','guwahati', 'vizag'])){
                $title = 'Internship in '.ucfirst($location_name).' | Internshala';
            }
        }
        $heading = "";
        if ($locations_count > 1 || $categories_count > 1) {
            $title = 'Internship | Summer Internship ' . date('Y') . ' | Internship in India';
            $meta_description = 'Apply to 2000+ summer and winter internships all over India and abroad with stipend across all streams. Apply and register for free now.';
            $heading = "Internships";
        }

        if ($ppo_checked && ($categories_count > 1 || $locations_count > 1)) {
            $location_name_to_display = "in " . $location_name;
            $title = 'Internships with job offer';
            $meta_description = 'Find the best paid summer internships with job offer in multiple locations and various profiles in India. Apply for free now.';
        }

        if ($wfh && ($categories_count > 1 || $locations_count > 1)) {
            $location_name_to_display = "in " . $location_name;
            $title = 'Work From Home Internships | Online Internships';
            $meta_description = 'Are you looking for work from home internships in ' . date('Y') . '? Find 1,500+ work from home internships with stipend. Apply now and earn by working from home.';
        }

        if ($internshipsCount && ($part_time || $wfh)) {
            $title = "$internshipsCount $title";
        }

        $meta_description = date('d-M-Y') . " " . $meta_description;
        return array(
            'title' => $title,
            'meta_description' => $meta_description,
            'heading' => $heading,
            'segment' => $segment
        );
    }

    public function seo_internship_faq(array $query): array {

        $category_name = $query['categories_name'] ? $query['categories_name'][0] : NULL;
        $categories_count = isset($query['categories_name']) ? count($query['categories_name']) : 0;

        $location_name = $query['locations_name'] ? $query['locations_name'][0] : NULL;
        $locations_count = $query['locations_name'] ? count($query['locations_name']) : 0;
        $matching_preference = $query['matching_preference'] ? $query['matching_preference'] : FALSE;
        $remote_job = $query['remote_job'] ?? '';
        $to_add_pgc_faqs = true;
        $to_add_cources_faqs = true;

        $seo_utils = new Utils();
        $internshal_trainings = $seo_utils->get_internshal_trainings($this->em, $category_name);
        //default - /internships/ (WFH yet to be added)
        $faq_array = array(
            [
                "question" => "How to search for internships in my preferred category/profile?",
                "answer" => "Click <a href='". base_url() . ltrim(CommonValues::INTERNSHIP_SEARCH_PAGE, '/') . "'>here</a> if you are looking for internships. Please remember to update your preferences (profile or location) and use relevant filters to find internships in your preferred profile/location."
            ],
            [
                "question" => "How can I apply for an internship on Internshala?",
                "answer" => "You can apply for an internship using the following steps-<br>"
                            . "<ul>"
                                . "<li>Click on \"View Details\" to get details about the company and the profile.</li>"
                                . "<li>Go through the details thoroughly and apply if your profile matches the requirements of the company.</li>"
                                . "<li>Click on \"Apply Now\" and follow the steps to submit your application.</li>"
                                . "<li>If not registered on Internshala, first register yourself and then click on \"Apply Now\".</li>"
                            . "</ul>"
            ],
            [
                "question" => "Do I need to pay to apply for an internship on Internshala?",
                "answer" => "Absolutely not! It's a free platform. You need not pay anything to apply on Internshala."
            ],
            [
                "question" => "What all internships are available on Internshala?",
                "answer" => "You can find 45,000+ internships, work from home internships and part-time internships in your preferred location or profile on Internshala."
            ],
        );

        if ($matching_preference) {
        } else {
            if ($category_name) {
                if ($categories_count == 1) {//only categories no location
                    $faq_array = array(
                        [
                            "question" => "How to search for " . strtolower($category_name). " internships?",
                            "answer" => "It is super easy to find " . ucfirst($category_name). " internships on Internshala. Simply add " . strtolower($category_name). " as your preferred category or use the category filter on the internships search page to find internships in your desired profile."
                        ],
                        [
                            "question" => "Where are the best " . strtolower($category_name). " internships available?",
                            "answer" => ucfirst($category_name) . " internships are available across various locations in India. Top 5 locations are-<br>"
                                            . "<ol>"
                                                . "<li>Delhi</li>"
                                                . "<li>Bangalore</li>"
                                                . "<li>Hyderabad</li>"
                                                . "<li>Pune</li>"
                                                . "<li>Kolkata</li>"
                                            . "</ol>"
                        ],
                        [
                            "question" => "Do I need to pay to apply for an internship on Internshala?",
                            "answer" => "Absolutely not! It's a free platform. You need not pay anything to apply on Internshala."
                        ],
                        [
                            "question" => "How can I apply for a " . strtolower($category_name). " internship on Internshala?",
                            "answer" => "You can apply for an internship using the following steps-<br>"
                                        . "<ul>"
                                            . "<li>Click on \"View Details\" to get details about the company and the profile.</li>"
                                            . "<li>Go through the details thoroughly and apply if your profile matches the requirements of the company.</li>"
                                            . "<li>Click on \"Apply Now\" and follow the steps to submit your application.</li>"
                                            . "<li>If not registered on Internshala, first register yourself and then click on \"Apply Now\".</li>"
                                        . "</ul>"
                        ],
                    );
                    if (isset($internshal_trainings['pgc'])) {
                        $to_add_pgc_faqs = false;
                        $faq_array[] = [
                            'question' => "Are there any placement-guaranteed courses for " . strtolower($category_name). "?",
                            'answer' => "You can check out the <a target='_blank' href='{$internshal_trainings['pgc']['url']}'>{$internshal_trainings['pgc']['name']} course with placement guarantee</a>."
                        ];
                    }

                    if (isset($internshal_trainings['course'])) {
                        $to_add_cources_faqs = false;
                        $faq_array[] = [
                            'question' => "How do I get certified in " . strtolower($category_name). "?",
                            'answer' => "You can check out the <a target='_blank' href='{$internshal_trainings['course']['url']}'>{$internshal_trainings['course']['name']} course</a> by Internshala to get certified."
                        ];
                    }
                }
            }
            if ($location_name) {
                if ($locations_count == 1) {//only location no categories
                    $to_add_pgc_faqs = false;
                    $to_add_cources_faqs = false;
                    $faq_array = array(
                        [
                            "question" => "How to search for internships in " . ucfirst($location_name) . "?",
                            "answer" => "It is super easy to find internships in " . ucfirst($location_name) . " on Internshala. Simply add " . ucfirst($location_name) . " as your preferred location or use the location filter on the internships search page to find internships in your desired location."
                        ],
                        [
                            "question" => "What are the best internships in " . ucfirst($location_name) . "?",
                            "answer" => "There are 100+ internship categories available in " . ucfirst($location_name) . ". The top 5 categories are-<br>"
                                        . "<ol>"
                                            . "<li>Sales & marketing</li>"
                                            . "<li>Content writing</li>"
                                            . "<li>Computer science</li>"
                                            . "<li>Graphic design</li>"
                                            . "<li>Human resource</li>"
                                        . "</ol>"
                        ],
                        [
                            "question" => "What type of internships are available in " . ucfirst($location_name) . "?",
                            "answer" => "You can find full-time internsips, work from home internships and part time internsips in your desired profile in $location_name."
                        ],
                        [
                            "question" => "Do I need to pay to apply for an internship on Internshala?",
                            "answer" => "Absolutely not! It's a free platform. You need not pay anything to apply on Internshala."
                        ],
                        [
                            "question" => "How can I apply for an internship in " . ucfirst($location_name) . " on Internshala?",
                            "answer" => "You can apply for an internship using the following steps-<br>"
                                        . "<ul>"
                                            . "<li>Click on \"View Details\" to get details about the company and the profile.</li>"
                                            . "<li>Go through the details thoroughly and apply if your profile matches the requirements of the company.</li>"
                                            . "<li>Click on \"Apply Now\" and follow the steps to submit your application.</li>"
                                            . "<li>If not registered on Internshala, first register yourself and then click on \"Apply Now\".</li>"
                                        . "</ul>"
                        ],
                    );
                    $faq_array[] = [
                        'question' => "Can I get a placement guarantee course in " . ucfirst($location_name) . "?",
                        'answer' => "You can check out the following courses for a placement guarantee in " . ucfirst($location_name) . " - " .
                            "<ul>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/digital-marketing-placement-guarantee-course/'>Digital Marketing course with placement</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/data-science-placement-guarantee-course/'>Data Science course with placement</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/full-stack-web-development-placement-guarantee-course/'>Full Stack Developer course with placement</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/product-management-placement-guarantee-course/'>Product Management course with placement</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/ui-ux-placement-guarantee-course/'>UI UX Design course with placement</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/human-resource-management-placement-guarantee-course/'>HR Course with placement</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/electric-vehicles-placement-guarantee-course/'>Electric Vehicle course with placement</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/sales-and-business-development-placement-guarantee-course/'>Business Development course with placement</a></li>" .
                            "</ul>"
                    ];

                    $faq_array[] = [
                        'question' => "How can I improve my skill set in {$location_name}?",
                        'answer' => "Internshala offers a number of certified courses to improve your skill set. Check them out here -" .
                            "<ul>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/web-development-course/'>Web Development Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/python-course/'>Python Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/hacking-course/'>Ethical Hacking Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/java-course/'>Java Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/digital-marketing-course/'>Digital Marketing Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/data-science-beginner-course/'>Data Science Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/tally-course/'>Tally Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/machine-learning-course/'>Machine Learning Course</a></li>" .
                            "<li><a target='_blank' href='https://trainings.internshala.com/ui-ux-design-course/'>UI UX Design Course</a></li>" .
                            "</ul>"
                    ];
                }
            }
            if ($category_name && $location_name) {
                $to_add_pgc_faqs = true;
                $to_add_cources_faqs = true;
                if ($categories_count == 1 && $locations_count == 1) {//1 location and 1 category
                    $faq_array = array(
                        [
                            "question" => "How to search for " . strtolower($category_name). " internships in " . ucfirst($location_name) . "?",
                            "answer" => "It is super easy to find " . strtolower($category_name). " internships in " . ucfirst($location_name) . " on Internshala. Simply add " . ucfirst($location_name) . " as your preferred location and " . strtolower($category_name). " as your preferred category or use the location and category filter on the internships search page to find internships in your desired location and profile."
                        ],
                        [
                            "question" => "What are the best internships in " . ucfirst($location_name) . "?",
                            "answer" => "There are 100+ internship categories available in " . ucfirst($location_name) . ". The top 5 categories are-<br>"
                                        . "<ol>"
                                            . "<li>Sales & marketing</li>"
                                            . "<li>Content writing</li>"
                                            . "<li>Computer science</li>"
                                            . "<li>Graphic design</li>"
                                            . "<li>Human resource</li>"
                                        . "</ol>"
                        ],
                        [
                            "question" => "Where are the best " . strtolower($category_name). " internships available?",
                            "answer" => ucfirst($category_name) . " internships are available across various locations in India. Top 5 locations are-<br>"
                                        . "<ol>"
                                            . "<li>Delhi</li>"
                                            . "<li>Bangalore</li>"
                                            . "<li>Hyderabad</li>"
                                            . "<li>Pune</li>"
                                            . "<li>Kolkata</li>"
                                        . "</ol>"
                        ],
                        [
                            "question" => "How can I apply for an internship in " . ucfirst($location_name) . " on Internshala?",
                            "answer" => "You can apply for an internship using the following steps-<br>"
                                        . "<ul>"
                                            . "<li>Click on \"View Details\" to get details about the company and the profile.</li>"
                                            . "<li>Go through the details thoroughly and apply if your profile matches the requirements of the company.</li>"
                                            . "<li>Click on \"Apply Now\" and follow the steps to submit your application.</li>"
                                            . "<li>If not registered on Internshala, first register yourself and then click on \"Apply Now\".</li>"
                                        . "</ul>"
                        ],
                    );
                    if (isset($internshal_trainings['pgc'])) {
                        $to_add_pgc_faqs = false;
                        $faq_array[] = [
                            'question' => "Are there any courses that offer a placement guarantee for {$category_name} in {$location_name}? ",
                            'answer' => "You can check out the <a target='_blank' href='{$internshal_trainings['pgc']['url']}'>{$internshal_trainings['pgc']['name']} course with placement guarantee </a> in {$location_name}."
                        ];
                    }
                    if (isset($internshal_trainings['course'])) {
                        $to_add_cources_faqs = false;
                        $faq_array[] = [
                            'question' => "How do I get certified in {$category_name} in {$location_name}?",
                            'answer' => "You can check out the <a target='_blank' href='{$internshal_trainings['course']['url']}'>{$internshal_trainings['course']['name']} course</a> by Internshala to get certified."
                        ];
                    }
                }
            }
        }

        if ($to_add_pgc_faqs) {
            $faq_array[] = [
                'question' => 'Are there any courses that offer a placement guarantee? ',
                'answer' => "You can check out the following courses for a placement guarantee -" .
                    "<ul>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/digital-marketing-placement-guarantee-course/'>Digital Marketing course with placement</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/data-science-placement-guarantee-course/'>Data Science course with placement</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/full-stack-web-development-placement-guarantee-course/'>Full Stack Developer course with placement</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/product-management-placement-guarantee-course/'>Product Management course with placement</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/ui-ux-placement-guarantee-course/'>UI UX Design course with placement</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/human-resource-management-placement-guarantee-course/'>HR Course with placement</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/electric-vehicles-placement-guarantee-course/'>Electric Vehicle course with placement</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/sales-and-business-development-placement-guarantee-course/'>Sales and Business Development course with placement</a></li>" .
                    "</ul>"
            ];
        }

        if ($to_add_cources_faqs) {
            $faq_array[] = [
                'question' => 'How do I get certified online?',
                'answer' => "Internshala offers a number of certified courses to improve your skill set. Check them out here - " .
                    "<ul>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/web-development-course/'>Web Development Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/python-course/'>Python Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/hacking-course/'>Ethical Hacking Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/java-course/'>Java Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/digital-marketing-course/'>Digital Marketing Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/data-science-beginner-course/'>Data Science Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/tally-course/'>Tally Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/machine-learning-course/'>Machine Learning Course</a></li>" .
                    "<li><a target='_blank' href='https://trainings.internshala.com/ui-ux-design-course/'>UI UX Design Course</a></li>" .
                    "</ul>"
            ];
        }

        return $faq_array;
    }

    public function seo_internship_breadcrumbs(array $query, int $filters_count): array {
        $category_name = $query['categories_name'] ? $query['categories_name'][0] : NULL;
        $categories_count = isset($query['categories_name']) ? count($query['categories_name']) : 0;

        $location_name = $query['locations_name'] ? $query['locations_name'][0] : NULL;
        $locations_count = $query['locations_name'] ? count($query['locations_name']) : 0;
        $wfh = $query['workFromHome'];

        $breadcrumbs_data = array();
        $page_url = CommonValues::INTERNSHIP_SEARCH_PAGE . '/';
        $to_add_breadcrumbs = false;
        $seo_utils = new Utils();
        $category_value = $category_name ? cf::make_string_seo_friendly($category_name) : null;
        $location_name_url = $location_name ? cf::make_string_seo_friendly($location_name) : null;

        $matching_preference = $query['matching_preference'] ?? FALSE;
        if ($category_name && $filters_count == 1) {
            if ($categories_count == 1) {
                $to_add_breadcrumbs = true;
                $breadcrumbs_data[] = array(
                    'name' => ucfirst($category_name) . " internships",
                    'item' => base_url($page_url . $category_value . '-internships/'),
                );
            }
        }
        if ($location_name && $filters_count == 1) {
            if ($locations_count == 1) {
                $to_add_breadcrumbs = true;
                $breadcrumbs_data[] = array(
                    'name' => "Internships in " . ucfirst($location_name),
                    'item' => base_url($page_url . 'internship-in-' . $location_name_url . '/')
                );

            }
        }
        if ($wfh && $category_name && $filters_count == 2) {
            if ($categories_count == 1) {
                $to_add_breadcrumbs = true;
                $breadcrumbs_data[] = array(
                    'name' => "Work from home",
                    'item' => base_url($page_url . 'work-from-home-internships/'),
                );
                $breadcrumbs_data[] = array(
                    'name' => "Work from home $category_name internships",
                    'item' => base_url($page_url . 'work-from-home-' . $category_value . '-internships/'),
                );
            }
        }

        if ($wfh && $location_name && $filters_count == 2) {
            if ($locations_count == 1) {
                $to_add_breadcrumbs = true;
                $breadcrumbs_data[] = array(
                    'name' => "Work from home",
                    'item' => base_url($page_url . 'work-from-home-internships/'),
                );
                $breadcrumbs_data[] = array(
                    'name' => "Work from home jobs in $location_name",
                    'item' => base_url($page_url . 'work-from-home-internships-in-' . $location_name_url . '/'),
                );
            }
        }


        if ($to_add_breadcrumbs || $filters_count == 0) {
            $breadcrumbs_data_initial = [
                [
                    'name' => 'Home',
                    'item' => base_url(),
                ],
                [
                    'name' => "Internships",
                    'item' => base_url($page_url),
                ]
            ];
            $breadcrumbs_data = array_merge($breadcrumbs_data_initial, $breadcrumbs_data);
        }
        if ($matching_preference) {
            $breadcrumbs_data = [];
        }
        return $breadcrumbs_data;

    }

}
