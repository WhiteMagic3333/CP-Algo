#include <numeric>
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
{   //took too long due to not clear logic, around 30 mins
    //proof please
    int n, k;
    cin >> n >> k;
    vector<ll> l(n), r(n);
    cin >> l >> r;
    vector<ll> mx, mn;
    for (int i = 0; i < n; i++) {
        if (l[i] > r[i]) {
            mx.push_back(l[i]);
            mn.push_back(r[i]);
        } else {
            mn.push_back(l[i]);
            mx.push_back(r[i]);
        }
    }
    ll ans = accumulate(mx.begin(), mx.end(), 0LL);
    sort(mn.begin(), mn.end(), greater<ll> ());
    for (int i = 0; i < k - 1; i++) {
        ans += mn[i];
    }
    cout << ans + 1;
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