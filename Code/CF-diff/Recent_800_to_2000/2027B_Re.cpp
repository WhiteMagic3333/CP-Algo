#include <iostream>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ordered_set oset;
    int max_kept = 0;

    for (int i = n - 1; i >= 0; i--) {
        
        int kept = 1 + oset.order_of_key({a[i] + 1, 0});
        
        if (kept > max_kept) {
            max_kept = kept;
        }
        
        oset.insert({a[i], i});
    }

    cout << n - max_kept << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}