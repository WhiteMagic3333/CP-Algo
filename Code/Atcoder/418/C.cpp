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
 
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n), pre(n, 0);
    cin >> arr;
    sort(arr.begin(), arr.end());
    //pre logic
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }
    while (q--) {
        ll b, ans = 0;
        cin >> b;
        //logic
        //first get the idx of last element < b
        // then get prefix_sum till that point,
        // add rem_elements * (b - 1) + 1;
        //thats your ans
        if (b > arr.back()) {
            ans = -1;
        } else {
            int idx = lower_bound(arr.begin(), arr.end(), b) - arr.begin() - 1;
            if (idx >= 0) {
                ans += pre[idx];
            }
            ans += (n - idx - 1) * (b - 1) + 1;
        }
        cout << ans << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}