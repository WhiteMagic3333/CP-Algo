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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    cin >> arr;
    ll low = 1, high = 2e18, ans = 1;
    while (low <= high) {
        ll mid = low + (high - low) / 2LL;
        bool valid = true;
        ll op = 0;
        for (int i = 0; i < n; i++) {
            ll idx = i + 1;
            if (arr[i] >= mid) {
                continue;
            }
            ll extra = mid - arr[i];
            ll q = extra / idx + (extra % idx != 0);
            op += q;
            if (op > k) {
                valid = false;
                break;
            }
        }
        if (valid) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}