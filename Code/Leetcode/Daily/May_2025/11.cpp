class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2; i < arr.size(); i++) {
            int sum = arr[i] % 2 + arr[i - 1] % 2 + arr[i - 2] % 2;
            if (sum == 3) {
                return true;
            }
        }
        return false;
    }
};