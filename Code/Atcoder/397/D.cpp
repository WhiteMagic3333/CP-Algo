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

// ll valid(ll a, ll b, ll c, ll d) {
//     // ax^2 + bx + c = 0の解
//     ll l = 0, r = 600000001;
//     while (r - l > 1) {
//         ll mid = (l + r) / 2;
//         if (a * mid * mid + b * mid + c <= 0)
//             l = mid;
//         else
//             r = mid;
//     }
//     if (a * l * l + b * l + c == 0){
//         cout << l << " " << l + d;
//         return true;
//     }
//     return false;
// }

ll sol(ll a, ll b, ll c) {
    ll low = 1, high = 1e9;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll cur = a * mid * mid + b * mid + c;
        if (cur > 0) {
            high = mid - 1;
        } else if (cur < 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

 
void solve()
{
    ll n;
    cin >> n;
    for (ll d = 1; d * d * d <= n; ++d) {
        // (k+d)^3 - k^3 = d^3 + 3*d^2k + 3*d*k^2 = n
        if (n % d != 0)
            continue;
        ll m = n / d; // =3*k^2 + 3*dk + d^2
        ll k = sol(3, 3 * d, d * d - m);
        if (k > 0) {
            cout << k + d << " " << k << endl;
            return;
        }
    }
    cout << -1 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}