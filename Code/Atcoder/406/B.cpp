#include <cstdint>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef uint64_t ll;
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

ll pow(ll a, ll b) {
    ll m = 1;
    while (b--) {
        m *= a;
    }
    return m;
}
 
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    cin >> arr;
    ll m = 1;
    ll mx = pow(10, k);
    for (auto i : arr) {
        ll rem = mx / m;
        if (rem < i) {
            m = 1;
        } else {
            if ((m * i) == mx) {
                m = 1;
            } else {
                m *= i;
            }
        }
    }
    cout << m;

}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}