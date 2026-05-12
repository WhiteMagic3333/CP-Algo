#include <algorithm>
#include <array>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <vector>

using namespace std;
typedef long long ll;

void print(array<int, 3> it) {
    cout << it[0] << " " << it[1] << "\n";
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> LR, RL;
    
    for (int i = 1; i <= m; i++) {
        int s, e;
        cin >> s >> e;
        LR.push_back({s, e, i - 1});
        RL.push_back({e, s, i - 1});
    }

    sort(LR.begin(), LR.end());
    sort(RL.begin(), RL.end());

    vector<bool> it_covers_other(m, false);

    int mn = 1e9 + 1;
    for (int i = m - 1; i >= 0; i--) {
        if (mn <= LR[i][1] || (i != 0 && LR[i][0] == LR[i - 1][0])) {
            it_covers_other[LR[i][2]] = true;
        }
        mn = min(LR[i][1], mn);
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        auto it = lower_bound(LR.begin(), LR.end(), array<int, 3>{l, r, 0});
        
        if (it != LR.end() && (*it)[0] == l && (*it)[1] == r) {
            cout << (it_covers_other[(*it)[2]] ? "Yes\n" : "No\n");
        } 
        else {
            auto it2 = lower_bound(RL.begin(), RL.end(), array<int, 3>{r, l, 0});
            
            if (it != LR.begin() && (*--it)[0] == l && it2 != RL.end() && (*it2)[0] == r && (*it2)[1] <= (*it)[1] + 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}