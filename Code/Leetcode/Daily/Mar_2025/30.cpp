class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length(), prev = -1, part_end = 0;
        vector<int> ans;
        unordered_map<char, int> last_occurence;
        for (int i = 0; i < n; i++) {
            last_occurence[s[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            part_end = max(part_end, last_occurence[ch]);
            if (i == part_end) {
                ans.push_back(part_end - prev);
                prev = part_end;
            }
        }
        return ans;
    }
};