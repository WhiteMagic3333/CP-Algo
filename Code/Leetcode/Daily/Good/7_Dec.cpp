class Solution {
public:
    int minimumSize(vector<int>& nums, int op) {
        //good question
        long long low = 1, high = 1e9, ans = 1e9;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            int op2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > mid) {
                    op2 += (nums[i] - 1) / mid;
                }
            }
            if (op2 > op) {
                low = mid + 1;
            } else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};