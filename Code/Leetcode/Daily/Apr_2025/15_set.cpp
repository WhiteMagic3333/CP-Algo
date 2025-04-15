#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        //this is a special set in which one can get the index of the sorted value stored
        int n = nums1.size();
        vector<int> index(n, 0);
        for (int i = 0; i < nums2.size(); i++) {
            index[nums2[i]] = i;
        }

        ordered_set s;
        long long ans = 0;

        for (auto e : nums1) {
            int idx = index[e];
            long long left = s.order_of_key(idx);
            long long right = (n - idx - 1) - (s.size() - left);
            ans += left * right;
            s.insert(idx);
        }
        return ans;
    }
};