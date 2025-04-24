typedef long long ll;
class Solution {
public:
    void pre_min(ll n, vector<vector<ll>> &seg) {
        ll rows = log2(n) + ((n & (n - 1)) ? 2 : 1);
        ll cur = n + n % 2;
        seg.resize(rows);
        for (int i = 0; i < rows; i++) {
            seg[i].resize(cur, 1e10);
            cur = cur / 2 + cur % 2;
        }
    
    }
    void build_min(vector<vector<ll>> &seg, int i, int element) {
        seg[0][i] = element;
        ll other;
        for (int k = 1; k < int(seg.size()); k++)
        {
            if (i % 2)
                other = seg[k - 1][i - 1];
            else
                other = seg[k - 1][i + 1];
            ll first = seg[k - 1][i];
            i = i / 2;
            seg[k][i] = min(first, other);
        }
    }
    ll query_min(vector<vector<ll>> &seg, int i, int j) {
        ll ans = 1e10, k = 0;
        i = i * 2, j = j * 2;
        do {
            i = i / 2;
            j = j / 2;
            if (i % 2) {
                ans = min(ans, seg[k][i]);
                i++;
            }
            if (j % 2 == 0) {
                ans = min(ans, seg[k][j]);
                j--;
            }
            k++;
        } while (i < j);
        return ans;
    }
    void pre_max(ll n, vector<vector<ll>> &seg) {
        ll rows = log2(n) + ((n & (n - 1)) ? 2 : 1);
        ll cur = n + n % 2;
        seg.resize(rows);
        for (int i = 0; i < rows; i++) {
            seg[i].resize(cur, 0);
            cur = cur / 2 + cur % 2;
        }
    
    }
    void build_max(vector<vector<ll>> &seg, int i, int element) {
        seg[0][i] = element;
        ll other;
        for (int k = 1; k < int(seg.size()); k++)
        {
            if (i % 2)
                other = seg[k - 1][i - 1];
            else
                other = seg[k - 1][i + 1];
            ll first = seg[k - 1][i];
            i = i / 2;
            seg[k][i] = max(first, other);
        }
    }
    ll query_max(vector<vector<ll>> &seg, int i, int j) {
        ll ans = 0, k = 0;
        i = i * 2, j = j * 2;
        do {
            i = i / 2;
            j = j / 2;
            if (i % 2) {
                ans = max(ans, seg[k][i]);
                i++;
            }
            if (j % 2 == 0) {
                ans = max(ans, seg[k][j]);
                j--;
            }
            k++;
        } while (i < j);
        return ans;
    }

    long long countSubarrays(vector<int>& arr, int minK, int maxK) {
        // can use fenwick tree for range min and range max
        // then for each i, get an index j by binary search
        // get min and max arr[i] for indexes in the range(i, j)
        // if ((min < minK && max < maxk) || (max > maxk && min > mink)) 
        // then no extra answers but if (min == mink && max == maxk)
        // then bs on i-j for subarray start and j->n - 1 for subarray end
        // subarray start is the first index where condition is correct
        // subarray end is the last
        int n = arr.size();
        vector<vector<ll>> range_min, range_max;
        pre_min(n, range_min);
        pre_max(n, range_max);
        for (int i = 0; i < n; i++) {
            build_min(range_min, i, arr[i]);
            build_max(range_max, i, arr[i]);
        }
        // cout << "\n";
        // //arr is O based hile range is 1 based
        long long ans = 0;
        // for (int i = 0; i < n; i++) {
        //     //get last valid index;
        //     int low = i, high = n - 1, last = -1;
        //     while (low <= high) {
        //         int mid = low + (high - low) / 2;
        //         int mx = query_max(range_max, i, mid);
        //         int mn = query_min(range_min, i, mid);
        //         if (mn > minK && mx < maxK) {
        //             low = mid + 1;
        //         } else if ((mn < minK && mx < maxK) || (mx > maxK && mn > minK)) {
        //             break;
        //         } else if (mn == minK && mx == maxK) {
        //             last = mid;
        //             low = mid + 1;
        //         } else if (mn < minK || mx > maxK) {
        //             high = mid - 1;
        //         }
        //     }

        //     if (last > -1) {
        //         // int first = -1;
        //         // low = i, high = last;
        //         // while (low <= high) {
        //         //     int mid = low + (high - low) / 2;
        //         //     // cout << "low, mid = " << low << ',' << mid << "\n";
        //         //     int mx = range_max.range_query(i, mid);
        //         //     int mn = range_min.range_query(i, mid);
        //         //     // cout << "mn, mx = " << mn << ',' << mx << '\n';
        //         //     if (mn > minK || mx < maxK) {
        //         //         low = mid + 1;
        //         //     } else if (mn == minK && mx == maxK) {
        //         //         first = mid;
        //         //         high = mid - 1;
        //         //     } else {
        //         //         high = mid - 1;
        //         //     }
        //         // }
        //         // ans += (last - first + 1);
        //         // cout << "{" << first << " " << last << "}";
        //     } else {
        //         cout << "{}";
        //     }
        // }
        return ans;
    }
};