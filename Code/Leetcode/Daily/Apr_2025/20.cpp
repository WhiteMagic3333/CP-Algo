class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> freq(1001, 0);
        for (auto i : answers) {
            freq[i + 1]++;
        }
        int ans = 0;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i]) {
                int q = freq[i] / i + (freq[i] % i > 0);
                ans += i * q;
            }
        }
        return ans;
    }
};