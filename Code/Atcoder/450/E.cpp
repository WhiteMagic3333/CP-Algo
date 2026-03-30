#include <vector>
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

long long letters(vector<ll> &freq) {
    ll total = 0;
    for (auto &i : freq) {
        total += i;
    }
    return total;
}
 
void solve()
{
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    vector<vector<ll>> pre1(n, vector<ll> (26, 0)); 
    vector<vector<ll>> pre2(m, vector<ll> (26, 0));
    pre1[0][x[0] - 'a']++;
    pre2[0][y[0] - 'a']++;
    for (int i = 1; i < n; i++) {
        pre1[i] = pre1[i - 1];
        pre1[i][x[i] - 'a']++;
    }
    for (int i = 1; i < m; i++) {
        pre2[i] = pre2[i - 1];
        pre2[i][y[i] - 'a']++;
    }
    vector<vector<ll>> dp(2, vector<ll> (26, 0));
    dp[0] = pre1.back();
    dp[1] = pre2.back();
    ll len = letters(dp[0]) + letters(dp[1]);
    // cout << len;
    ll _mx = 1e18;
    while (len <= _mx) {
        vector<ll> cur = dp.back();
        for (int i = 0; i < 26; i++) {
            cur[i] += dp[dp.size() - 2][i];
        }
        dp.push_back(cur);
        len += letters(dp.back());
    }
    cout << dp.size();
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}