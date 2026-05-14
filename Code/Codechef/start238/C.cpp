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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, x;
            cin >> u >> x;
            u--;
            a[u] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int m = r - l + 1;
            if (m == 1) {
                cout << a[l] << "\n";
            } else if (m % 2 == 0) {
                int k = m / 2;
                cout << max(a[l + k - 1], a[l + k]) << "\n";
            } else {
                int k = m / 2;
                cout << max(min(a[l + k - 1], a[l + k]), min(a[l + k], a[l + k + 1])) << "\n";
            }
        }
    }
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
    }
    return 0;
}