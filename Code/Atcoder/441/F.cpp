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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> pre(n + 2, vector<ll> (m + 1, 0));
    vector<vector<ll>> suf(n + 2, vector<ll> (m + 1, 0));
    vector<ll> p(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        int idx = i - 1;
        for (int j = p[idx]; j <= m; j++) {
            pre[i][j] = max({pre[i][j], pre[i - 1][j - p[idx]] + v[idx], pre[i][j - 1]});
        }
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        int idx = i - 1;
        for (int j = p[idx]; j <= m; j++) {
            suf[i][j] = max({suf[i][j], suf[i + 1][j - p[idx]] + v[idx], suf[i][j - 1]});
        }
    }
    ll best = pre[n][m];
    string ans = "";
    for (int i = 1; i <= n; i++) {
        int idx = i - 1;
        //check if without stock at idx can we make a value best
        ll best_without = 0;
        ll best_with = 0;
        for (int j = 0; j <= m; j++) {
            best_without = max(best_without, pre[i - 1][j] + suf[i + 1][m - j]);
            if ((m - j - p[idx]) >= 0) {
                best_with = max(best_with, v[idx] + pre[i - 1][j] + suf[i + 1][m - j - p[idx]]);
            }
        }
        if (best_with == best && best_without != best) {
            ans.push_back('A');
        } else if (best_with == best) {
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