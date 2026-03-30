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

ll fun(vector<ll> &idx, int l, int r) {
    ll ans = 0;
    for (int i = 0; i < idx.size(); i++) {
        auto it1 = lower_bound(idx.begin(), idx.end(), idx[i] + l);
        auto it2 = lower_bound(idx.begin(), idx.end(), idx[i] + r + 1);
        ans += it2 - it1;
    }
    return ans;
}
 
void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    string str;
    cin >> str;
    vector<vector<ll>> f(26);
    for (int i = 0; i < str.length(); i++) {
        f[str[i] - 'a'].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += fun(f[i], l, r);
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