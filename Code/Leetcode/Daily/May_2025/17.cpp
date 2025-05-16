class Solution {
public:
    void sortColors(vector<int>& arr) {
        //0's on left and 2's on right
        int l = 0, m = 0, r = arr.size() - 1;
        while (m <= r) {
            if (arr[m] == 0) {
                swap(arr[m], arr[l]);
                l++;
                m = max(l, m);
            } else if (arr[m] == 2) { // 2
                swap(arr[m], arr[r]);
                r--;
            } else {
                m++;
            }
        }
    }
};