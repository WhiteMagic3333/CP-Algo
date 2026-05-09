#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>

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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    cin >> a;
    string str;
    cin >> str;
    vector<ll> s;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            s.push_back(a[i]);
        }
        mx = max(mx, a[i]);
    }
    sort(s.begin(), s.end());
    ll ans = (s.size() == 0) ? 0 : s.front() * s.back();
    n = s.size();
    ll c = 0;
    for (int i = 0; i < n; i++, c++) {
        ans = max(ans, s[i] * s.back() - c * x);
        ans = max(ans, s[i] * mx - (c + 1) * x);
    }
    ans = max(ans, mx * mx - ((n + 1) * x));
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