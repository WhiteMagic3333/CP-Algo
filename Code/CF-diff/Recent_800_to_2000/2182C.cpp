#include <algorithm>
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
//couldnt derive the solution
//should have gone in depth, underestimated thee difficulty
// took 1 hour+
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    cin >> a >> b >> c;
    ll ans = 0;
    //first is fixed
    //only differece is required
    //i is 0
    ll q1 = 0;
    for (int diff = 0; diff < n; diff++) {
        bool valid = true;
        for (int j = 0; j < n; j++) {
            if (a[j] >= b[(j + diff) % n]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            q1++;
        }
    }
    ll q2 = 0;

    for (int diff = 0; diff < n; diff++) {
        bool valid = true;
        for (int j = 0; j < n; j++) {
            if (b[j] >= c[(j + diff) % n]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            q2 += n;
        }
    }

    cout << q1 * q2;
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