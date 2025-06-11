#include <bits/stdc++.h>
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
 
using i128 = __int128;
using u128 = unsigned __int128;
 
void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> p(n), ip(n);
    for (int i = 0; i < n; i++) { //converted to 0 based, all three, values and idxs
        std::cin >> p[i];
        p[i]--;
        ip[p[i]] = i;
    }
    
    for (int i = 0; i < q; i++) {
        int l, r, x;
        std::cin >> l >> r >> x;
        l--;//0 based
        r--;
        x--;
        
        if (ip[x] < l || ip[x] > r) {
            std::cout << -1 << " \n"[i == q - 1];
            continue;
        }
        
        int lgood = 0, ggood = 0;
        int lbad = 0, gbad = 0;
        
        while (true) {
            int m = (l + r) / 2;
            if (p[m] == x) {
                break;
            }
            if (ip[x] < m) {
                if (p[m] > x) {
                    ggood++;
                } else {
                    gbad++;
                }
                r = m - 1;
            } else {
                if (p[m] < x) {
                    lgood++;
                } else {
                    lbad++;
                }
                l = m + 1;
            }
        }
        
        if (lgood + lbad > x || ggood + gbad > n - 1 - x) {
            std::cout << -1 << " \n"[i == q - 1];
            continue;
        }
        
        std::cout << std::max(lbad, gbad) * 2 << " \n"[i == q - 1];
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}