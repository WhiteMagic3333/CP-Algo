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
    return out;
}
 
void solve()
{   //9:16 okaish, first under 10 mins i guess
    ll a, b;
    cin >> a >> b;
    ll a_bits = __builtin_popcount(a);
    ll b_bits = __builtin_popcount(b);
    vector<int> ans;
    for (int i = 0; i < 33; i++) {
        bool bit_a = (1LL << i) & a;
        bool bit_b = (1LL << i) & b;
        if (bit_a) {
            a_bits--;
        }
        if (bit_a != bit_b) {
            if (bit_a) {
                ans.push_back((1LL << i));
            } else {
                if (!a_bits) {
                    cout << "-1";
                    return;
                }
                ans.push_back((1LL << i));
            }
        }
    }
    cout << ans.size();
    if (ans.size()) {
        cout << "\n" << ans;
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