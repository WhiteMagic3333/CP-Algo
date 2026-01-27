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
    srand(time(0));
    ll n = 3;
    ll big = 100, small = 1;
    ll c = 1 + (rand() * 1LL + (big - small)) % (big + 1LL);
    cout << n << " " << c << "\n";
    big = 10;
    for (int i = 0; i < n; i++) {
        ll w = 1 + (rand() * 1LL) % 3;
        ll v = 1 + (rand() * 1LL + (big - small)) % (big + 1LL);
        ll k = 1 + (rand() * 1LL + (big - small)) % (big + 1LL);
        cout << w << " " << v << " " << k << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}