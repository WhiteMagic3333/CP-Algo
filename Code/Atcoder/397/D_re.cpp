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

bool valid(ll &i, ll &n) {
    ll a = i * i * i;
    ll low = 0, high = 1e6;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll cur = mid * mid * mid + n;
        if (cur < a) {
            low = mid + 1;
        } else if (cur > a) {
            high = mid - 1;
        } else {
            cout << i << " " << mid;
            return true;
        }
    }
    return false;
}

bool check(ll d, ll n) {
    //3
    ll low = 1, high = 6e8 + 1;
}

void solve()
{
    ll x;
    cin >> x;
    for (ll d = 1; d * d * d <= x; d++) {
        if (x % d == 0 && check(d, x)) {
            return;
        }
    }
    cout << "-1";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}