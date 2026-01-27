#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
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
 
void solve()
{
    int n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    vector<vector<ll>> dpl(n + 2, vector<ll> (w + 1, 0));
    vector<vector<ll>> dpr(n + 2, vector<ll> (w + 1, 0));
    dpl[0][0] = 0;
    // //dp[i] -> max value till ith idx having max weight w
    for (int i = 1; i <= n; i++) {
        int idx = i - 1;
        dpl[i] = dpl[i - 1];
        for (int j = 0; j <= w; j++) {
           if (j > 0) {
                dpl[i][j] = max({dpl[i][j], dpl[i][j - 1]});
           }
           if (j - weight[idx] >= 0) {
                dpl[i][j] = max(dpl[i][j], dpl[i - 1][j - weight[idx]] + value[idx]);
           }
        }
    }
    dpr[n + 1][0] = 0;
    for (int i = n; i >= 1; i--) {
        int idx = i - 1;
        dpr[i] = dpr[i + 1];
        for (int j = 0; j <= w; j++) {
           if (j > 0) {
                dpr[i][j] = max({dpr[i][j], dpr[i][j - 1]});
           }
           if (j - weight[idx] >= 0) {
                dpr[i][j] = max(dpr[i][j], dpr[i + 1][j - weight[idx]] + value[idx]);
           }
        }
    }
    ll best = dpl[n][w];
    string ans = "";
    for (int i = 1; i <= n; i++) {
        int idx = i - 1;
        ll best_with = 0, best_without = 0;
        for (int j = 0; j <= w; j++) {
            best_without = max(best_without, dpl[i - 1][j] + dpr[i + 1][w - j]);
            if ((w - j - weight[idx]) >= 0) {
                best_with = max(best_with, dpl[i - 1][j] + value[idx] + dpr[i + 1][w - j - weight[idx]]);
            }
        }
        if (best_with == best && best_without != best) {
            ans.push_back('A');
        } else if (best_with == best && best_without == best) {
            ans.push_back('B');
        } else {
            ans.push_back('C');
        }
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}