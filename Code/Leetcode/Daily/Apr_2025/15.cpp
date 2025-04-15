using ll = long long;
class Fenwick {
public:
    vector<ll> tree;
    Fenwick(int n) {
        tree.assign(n + 1, 0);
    }
    
    void update(int k, int x) {
        k++;
        while (k < tree.size()) {
            tree[k] += x;
            k += k & -k;  
        }
    }
    
    ll query(int k) {
        ll total = 0;
        k++;
        while (k > 0) {
            total += tree[k];
            k -= k & -k;
        }
        return total;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        //this is a special set in which one can get the index of the sorted value stored
        int n = nums1.size();
        vector<int> index(n, 0);
        for (int i = 0; i < nums2.size(); i++) {
            index[nums2[i]] = i;
        }

        Fenwick s(n);
        long long ans = 0;

        for (auto e : nums1) {
            int idx = index[e];
            long long left = s.query(idx);
            long long size = s.query(n - 1);
            long long right = (n - idx - 1) - (size - left);
            ans += left * right;
            s.update(idx, 1);
        }
        return ans;
    }
};