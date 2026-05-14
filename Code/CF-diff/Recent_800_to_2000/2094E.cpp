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
{   //11:45 (5 min thinking 6:5 min implementing)
    //masters take 3-5
    vector<int> bits(32, 0);
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    for (auto i : arr) {
        for (int j = 0; j < 32; j++) {
            if ((1 << j)&i) {
                bits[j]++;
            }
        }
    }
    ll ans = 0;
    for (auto i : arr) {
        int set = 0;
        ll cur = 0;
        for (int j = 0; j < 32; j++) {
            if ((1 << j)&i) {
                set = n - bits[j];
                cur += (1LL << j) * set;
            } else {
                set = bits[j];
                cur += (1LL << j) * set;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans;
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