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

ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}
 
void solve()
{
    int n;
    cin >> n;
    vector<long long> p(n), e(n);
    cin >> p >> e;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = lcm(p[i], e[i]);
    }
    ll g = 0;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, arr[i]);
        if (g != p[i]) {
            cout << "No";
            return;
        }
    }
    g = 0;
    for (int i = n - 1; i >= 0; i--) {
        g = __gcd(g, arr[i]);
        if (g != e[i]) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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

// redis saves deadlock issues in multithreading as it is single threaded
// and thread safety