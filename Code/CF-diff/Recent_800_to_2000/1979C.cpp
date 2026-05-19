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
    return (a * b) / (__gcd(a, b));
}
 
void solve()
{   //too long hard math
    //1 hr
    int n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    ll l = 1;
    for (auto i : arr) {
        l = lcm(i, l);
    }
    ll left = 0;
    ll right = l;
    for (auto i : arr) {
        left += (l / i);
    }
    if (left < right) {
        for (auto i : arr) {
            cout << l / i << " ";
        }
        return;
    }
    cout << "-1";
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