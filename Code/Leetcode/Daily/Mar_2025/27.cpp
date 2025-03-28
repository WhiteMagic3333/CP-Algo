class Solution {
public:
    int get_dominant(vector<int> &arr) {
        int cur_mx = arr[0], freq = 1;
        for (int i = 2; i < arr.size(); i++) {
            freq += arr[i] == cur_mx ? 1 : -1;
            cur_mx = freq == 0 ? arr[i] : cur_mx;
            freq = max(freq, 1);
        }
        return cur_mx;
    }

    inline bool valid(int &freq, int _size) {
        return freq > (_size / 2);
    }

    int minimumIndex(vector<int>& nums) {
        //can be done in O(1) space and O(n) time
        int dominant_element = get_dominant(nums);//to be made
        int freq = count(nums.begin(), nums.end(), dominant_element);
        int left_freq = 0, right_freq = freq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == dominant_element) {
                left_freq++;
                right_freq--;
                if (valid(left_freq, i + 1) && valid(right_freq, (int)nums.size() - i - 1)) {
                    return i;
                }
            }
        }
        return -1;
    }
};n