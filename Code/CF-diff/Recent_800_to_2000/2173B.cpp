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
{   //too 11:30 mins, felt normal, i need to be faster than this
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    cin >> a >> b;
    //in the nth turn
    //we can do b[n - 1] - k (k is the most neg we can get)
    //or k - b[n - 1]
    ll mx_neg = 0, mx_pos = 0;
    for (int i = 0; i < n - 1; i++) {
        ll n_mx_neg = min({mx_neg - a[i], b[i] - mx_neg, mx_pos - a[i], b[i] - mx_pos});
        ll n_mx_pos = max({mx_neg - a[i], b[i] - mx_neg, mx_pos - a[i], b[i] - mx_pos});
        mx_neg = n_mx_neg;
        mx_pos = n_mx_pos;
    }
    ll ans = max({mx_pos - a[n - 1], b[n - 1] - mx_neg, mx_neg - a[n - 1], b[n - 1] - mx_pos});
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