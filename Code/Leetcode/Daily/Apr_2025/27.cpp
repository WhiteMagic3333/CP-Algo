class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int i = 2; i < arr.size(); i++) {
            if ((arr[i - 2] + arr[i]) * 2 == arr[i - 1]) {
                ans++;
            }
        }
        return ans;
    }
};