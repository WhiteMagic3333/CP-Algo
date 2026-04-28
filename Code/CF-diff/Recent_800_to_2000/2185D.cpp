#include <unordered_map>
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
    //took me 17 mins too long
    //master did it in 1 min - 6 mins
    ll n, m, h;
    cin >> n >> m >> h;
    vector<ll> a(n), b(m), c(m);
    cin >> a;
    for (int i = 0; i < m; i++) {
        cin >> b[i] >> c[i];
    }
    //when ever exceeds h resets all to zero
    int i = 0;
    unordered_map<int, int> f;
    while (i < m) {
        f[b[i] - 1] += c[i];
        if (f[b[i] - 1] + a[b[i] - 1] > h) {
            f.clear();
        }
        i++;
    }
    for (auto [i, val] : f) {
        a[i] += val;
    }
    cout << a;
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