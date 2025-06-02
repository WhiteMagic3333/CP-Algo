class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n, i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            int uphill = 0, downhill = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                uphill++;
                i++;
            }
            while (i < n && ratings[i] < ratings[i - 1]) {
                downhill++;
                i++;
            }
            int peak = max(uphill, downhill);
            if (peak == downhill) {
                swap(uphill, downhill);
            }
            downhill--;
            ans += uphill * (uphill + 1) / 2;
            ans += downhill * (downhill + 1) / 2;
        }
        return ans;
    }
};