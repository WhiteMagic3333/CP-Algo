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
    vector<ll> x(n), y(n);
    cin >> x >> y;
    vector<ll> idx(1001, -1);
     for (int i = 0; i < n; i++) {
        idx[x[i]] = i;
    }
    ll prev = -1;
    for (int i = 1; i < n; i++) {
        ll diff = y[i] - y[0];
        diff = abs(diff);
        if (diff < prev || (diff == prev && y[i] < y[i - 1])) {
            return void(cout << "-1");
        }
        prev = diff;
    }
    cout << idx[y[0]] + 1;
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