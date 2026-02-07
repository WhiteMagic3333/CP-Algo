#include <algorithm>
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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    vector<ll> pre(n, 1e9), suf(n, 1e9);
    pre[0] = arr[0];
    suf[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++) {
        pre[i] = min(pre[i - 1] + 1, arr[i]);
        suf[n - i - 1] = min(arr[n - i - 1], suf[n - i] + 1);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll mn = min(suf[i], pre[i]);
        ans += abs(mn - arr[i]);
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}