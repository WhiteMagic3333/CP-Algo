class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        vector<int> freq(2001, 0);
        unordered_map<int, bool> vis;
        int dis = 0, n = nums.size(), ans = 0;
        for (auto i : nums) {
            dis += vis[i] == false;
            vis[i] = true;
        }
        int i = 0, j = 0, dis2 = 0, rem;
        while (j < n) {
            while (j < n && dis2 < dis) {
                dis2 += freq[nums[j]] == 0;
                freq[nums[j]]++;
                j++;
            }
            rem = n + 1 - j;
            while (i < j && dis2 >= dis) {
                ans += rem;
                freq[nums[i]]--;
                dis2 -= freq[nums[i]] == 0;
                i++;
            }
        }
        return ans;
    }
};