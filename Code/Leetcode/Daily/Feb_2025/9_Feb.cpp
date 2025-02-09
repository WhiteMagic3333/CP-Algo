class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        /*
        num  = 1 2 4 4 5 6
        diff = 0 1 1 1 1 1
        num[i] - i != num[j] - j; 
        */
        unordered_map<int, int> f;
        long long total = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += total - f[nums[i] - i];
            f[nums[i] - i]++;
            total++;
        }
        return ans;
    }
};