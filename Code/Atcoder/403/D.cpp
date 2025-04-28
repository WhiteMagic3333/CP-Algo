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

ll fun(vector<ll> &dp, int i) {
    if (i < 0) {
        return 0;
    }
    return dp[i];
}
 
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<ll> arr(n), freq(1e6 + 5, 0), dp(1e6 + 5, 0);
    cin >> arr;
    ll mx = 0, extra = 0;
    for (auto i : arr) {
        freq[i]++;
        if (freq[i] > 1) {
            extra++;
        }
        mx = max(mx, i);
    }
    if (d == 0) {
        cout << extra;
        return;
    }
    queue<ll> q;
    for (int i = 0; i <= mx; i++) {
        ll old_freq = 0;
        if ((i - d) >= 0) {
            old_freq = freq[i - d];
        }
        dp[i] = min(freq[i] + fun(dp, i - d), old_freq + fun(dp, i - 2 * d));
        q.push(dp[i]);
        if (q.size() > d) {
            q.pop();
        }
    }
    ll ans = 0;
    while (q.size()) {
        ans += q.front();
        q.pop();
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