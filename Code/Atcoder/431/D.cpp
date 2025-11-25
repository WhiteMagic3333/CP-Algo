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

ll fun(vector<array<ll, 3>> &h, ll &hw, ll &bw) {
    ll _w = hw - bw;
    if (_w <= 0) {
        return 0;
    }
    _w = _w / 2 + _w % 2;
    //remove extra weight(w) from h and get the min possible sum(hw - bw) from weight w
    vector<ll> vis(hw + 505, false);
    vector<ll> dp(hw + 505, 1e18);
    vis[0] = 1;
    dp[0] = 0;
    for (auto &cur : h) {
        ll w = cur[0], hp = cur[1], bp = cur[2];
        for (int i = hw; i >= 0; i--) {
            if (vis[i]) {
                vis[i + w] = true;
                dp[i + w] = min(dp[i + w], dp[i] + hp - bp);
            }
        }
    }
    ll ans = 1e18;
    for (int i = _w; i < hw + 505; i++) {
        if (vis[i]) {
            ans = min(ans, dp[i]);
        }
    }
    return ans;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<array<ll, 3>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    ll body = 0, head = 0;
    ll happy = 0;
    vector<array<ll, 3>> h;
    for (array<ll, 3> cur : arr) {
        if (cur[1] <= cur[2]) {
            body += cur[0];
            happy += cur[2];
        } else {
            h.push_back(cur);
            head += cur[0];
            happy += cur[1];
        }
    }
    //h array has all heads pts more than body
    cout << happy - fun(h, head, body);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}