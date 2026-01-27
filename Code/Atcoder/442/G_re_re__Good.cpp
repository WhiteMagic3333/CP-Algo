#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] && i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}
 
template<typename T>
std::istream& operator>>(std::istream&in, std::vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}
 
template<typename T>
std::ostream& operator<<(std::ostream&out, std::vector<T>& v) {
    for (const T& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
    return out;
}

ll n;
 
void solve()
{
    //idea using greedy i can make
    //either c weight, c - 1, or c - 2
    // try removing 1 or 2 weight and add more to find the best ans
    ll c;
    cin >> n >> c;
    vector<array<ll, 4>> items;
    for (int i = 0; i < n; i++) {
        ll w, v, k;
        cin >> w >> v >> k;
        ll net_val = 2 * v;
        if (w == 1) {
            net_val = 6 * v;
        } else if (w == 2) {
            net_val = 3 * v;
        }
        items.push_back({net_val, w, v, k});
    }
    sort(items.begin(), items.end(), greater<array<ll, 4>> ());
    // cout << "GV w v k\n";
    // for (auto item : items) {
    //     cout << item[0] << " " << item[1] << " " << item[2] << " " << item[3] << "\n";
    // }
    // cout << "\n\n";
    ll inf = 1e18;
    vector<ll> dp(7, inf);
    int idx = -1;
    ll cap = 0;
    ll ans = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        ll w = items[i][1], k = items[i][3], v = items[i][2];
        if ((cap + w * k) <= c) {
            cap += w * k;
            ans += v * k;
            for (int j = 6 - w; j >= 0; j--) {
                if (dp[j] != inf) {
                    dp[j + w] = min(dp[j + w], v + dp[j]);
                }
            }
            if (k > 1) {
                for (int j = 6 - w; j >= 0; j--) {
                    if (dp[j] != inf) {
                        dp[j + w] = min(dp[j + w], v + dp[j]);
                    }
                }
            }
        } else {
            ll items_used = (c - cap) / w;
            cap += w * items_used;
            ans += v * items_used;
            for (int j = 6 - w; j >= 0; j--) {
                if (dp[j] != inf) {
                    dp[j + w] = min(dp[j + w], v + dp[j]);
                }
            }
            if (items_used > 1) {
                for (int j = 6 - w; j >= 0; j--) {
                    if (dp[j] != inf) {
                        dp[j + w] = min(dp[j + w], v + dp[j]);
                    }
                }
            }
            items[i][3] -= items_used;
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << ans;
        return;
    }
    ll f_ans = ans;
    ll neg_inf = -1e18;
    vector<ll> dp2(7, neg_inf);
    dp2[0] = 0;
    for (int i = idx; i < n; i++) {
        ll w = items[i][1], k = items[i][3], v = items[i][2];
        for (int j = 6 - w; j >= 0; j--) {
            if (dp2[j] != neg_inf) {
                dp2[j + w] = max(dp2[j + w], v + dp2[j]);
            }
        }
        if (k > 1) {
            for (int j = 6 - w; j >= 0; j--) {
                if (dp2[j] != neg_inf) {
                    dp2[j + w] = max(dp2[j + w], v + dp2[j]);
                }
            }
        }
    }
    cout << dp << dp2;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (cap - i + j <= c) {
                f_ans = max(f_ans, ans - dp[i] + dp2[j]);
            }
        }
    }
    cout << f_ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}