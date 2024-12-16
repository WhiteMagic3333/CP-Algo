class Solution {
public:
    int _beauty(vector<int> &arr, int cur, int k) {
        int mn = max(cur - k, 0);
        int mx = cur + k;
        auto _start = lower_bound(arr.begin(), arr.end(), mn);
        auto _end = upper_bound(arr.begin(), arr.end(), mx);
        if (_start == arr.end() || *_start > mx) {
            return 0;
        }
        if (_end == arr.end() || *_end > mx) {
            _end--;
        }
        return 1 + (_end - _start);
    }
    int maximumBeauty(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());
        int beauty = 1, cur = nums[0];
        for (int i = 0; i < 1e5 + 1; i++) {
            int cur_beauty = _beauty(nums, i, k);
            if (cur_beauty > beauty) {
                beauty = cur_beauty;
                cur = i;
            }
        }
        return beauty;
    }
};