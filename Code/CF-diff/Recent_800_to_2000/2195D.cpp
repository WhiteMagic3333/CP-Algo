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
{   //simple code, tough math behind
    //60 mins + upsolve nice idea
    //although i am feeling more confident day by day
    //I am getting much closer to math based problems
    int n;
    cin >> n;
    vector<ll> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    ll sum = (f[1] + f[n]) / (n - 1);
    vector<ll> a(n + 1);
    a[1] = (f[2] - f[1] + sum) / 2LL;
    ll prev = a[1];
    for (int i = 2; i < n; i++) {
        a[i] = (f[i + 1] - f[i] + sum) / 2 - prev;
        prev += a[i];
    }
    a[n] = sum - prev;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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
        cout << "\n";
    }
    return 0;
}