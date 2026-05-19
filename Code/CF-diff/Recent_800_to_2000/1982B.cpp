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
    //log op
    //13 mins
    ll x, k, y;
    cin >> x >> y >> k;
    while (k) {
        //x == 1
        if (x == 1) {
            //in one cycle we move from 1 to y
            //(y - 1) operations
            k = k % (y - 1);
            x += k;
            k = 0;
        } else {
            ll nxt = x / y;
            nxt++;
            nxt *= y;
            ll op = min(k, nxt - x);
            k -= op;
            x += op;
            while (x % y == 0) {
                x /= y;
            }
        }
    }
    cout << x;
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