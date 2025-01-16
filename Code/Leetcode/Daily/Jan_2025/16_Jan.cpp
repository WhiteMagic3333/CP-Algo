class Solution {
public:

    void add(vector<int> &bit_count, int cur) {
        for (int i = 0; i < 32; i++) {
            bit_count[i] += ((1 << i) & cur) > 0; 
        }
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> bit_count1(32, 0), bit_count2(32, 0);
        for (int e : nums1) {
            add(bit_count1, e);
        }
        for (int e : nums2) {
            add(bit_count2, e);
        }
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            long long sum = bit_count1[i] * (m - bit_count2[i]) + bit_count2[i] * (n - bit_count1[i]);
            ans += (sum % 2) ? (1 << i) : 0;
        }
        return ans;
    }
};