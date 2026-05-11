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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> by_L(n + 2);
    vector<vector<pair<int, int>>> by_R(n + 2);
    
    for (int i = 1; i <= m; i++) {
        int s, e;
        cin >> s >> e;
        by_L[s].push_back({e, i});
        by_R[e].push_back({s, i});
    }

    for (int i = 1; i <= n; i++) {
        sort(by_L[i].begin(), by_L[i].end());   // Sorted by R ascending
        sort(by_R[i].begin(), by_R[i].end());   // Sorted by L ascending
    }

    vector<vector<pair<int, int>>> min_R(n + 2);
    for (int i = n; i >= 1; i--) {
        vector<pair<int, int>> candidates;
        for (int j = 0; j < min(2, (int)by_L[i].size()); j++) {
            candidates.push_back(by_L[i][j]);
        }
        if (i < n) {
            for (auto p : min_R[i + 1]) {
                candidates.push_back(p);
            }
        }
        sort(candidates.begin(), candidates.end());
        
        for (int j = 0; j < min(2, (int)candidates.size()); j++) {
            min_R[i].push_back(candidates[j]);
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        bool possible = false;

        vector<pair<int, int>> best_A;
        auto itA = upper_bound(by_L[l].begin(), by_L[l].end(), make_pair(r + 1, -1));
        if (itA != by_L[l].begin()) {
            itA--;
            best_A.push_back(*itA);
            if (itA != by_L[l].begin()) {
                itA--;
                best_A.push_back(*itA);
            }
        }

        vector<pair<int, int>> best_B;
        auto itB = lower_bound(by_R[r].begin(), by_R[r].end(), make_pair(l, -1));
        if (itB != by_R[r].end()) {
            best_B.push_back(*itB);
            auto nxtB = itB; nxtB++;
            if (nxtB != by_R[r].end()) {
                best_B.push_back(*nxtB);
            }
        }

        for (auto A : best_A) {
            for (auto B : best_B) {
                if (A.second != B.second) { \
                    if (A.first + 1 >= B.first) { 
                        possible = true;
                    }
                }
            }
        }

        if (!best_A.empty() && best_A[0].first == r) {
            int exact_id = best_A[0].second;
            for (auto p : min_R[l]) {
                if (p.second != exact_id && p.first <= r) {
                    possible = true;
                }
            }
        }

        if (possible) cout << "Yes\n";
        else cout << "No\n";
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