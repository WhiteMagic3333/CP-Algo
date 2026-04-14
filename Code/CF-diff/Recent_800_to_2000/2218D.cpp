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
    //17:50 (rated 1100) adhoc logic is slow
    //improve speed on constructing test cases
    ll n;
    cin >> n;

    //construct a seq of n integers
    //st gcd(a[i],a[i+1]) == distinct for all i >= 0; i <= n - 2;
    //max element upto 1e18
    // 1 1*3 3*5 5*7 7*9 9*11 11*13
    ll cur = 1;
    for (int i = 0; i < n; i++) {
        cout << (cur * (cur + 2)) << " ";
        cur += 2;
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