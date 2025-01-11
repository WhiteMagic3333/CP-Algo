class Solution {
public:
    void add_frequency(string &word, vector<int> &freq) {
        for (char letter : word) {
            freq[letter - 'a']++;
        }
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> req_freq(26, 0);
        vector<string> ans;
        for (auto &word : words2) {
            vector<int> in_freq(26, 0);
            add_frequency(word, in_freq);
            for (int i = 0; i < 26; i++) {
                req_freq[i] = max(in_freq[i], req_freq[i]);
            }
        }
        for (auto &word : words1) {
            vector<int> freq(26, 0);
            add_frequency(word, freq);
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < req_freq[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};