#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_set os;
    

    int q;
    cin >> q;

    while (q--) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            // Insert x
            os.insert(x);
        } else if (type == 2) {
            // Count numbers strictly greater than x
            int total = os.size();
            int less_or_equal = os.order_of_key(x + 1);
            int greater = total - less_or_equal;

            cout << greater << "\n";
        }
    }

    return 0;
}
