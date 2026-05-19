#include <algorithm>
#include <numeric>
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
{   //too much time implementing
    //should have thought of implementation as well
    //yet again rushed and misunderstood the problem
    //yet again misunderstood after re reading the problem
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> arr(n);
    cin >> arr;
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    ll ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        ll l1 = sum - arr[i] - y;
        ll l2 = sum - arr[i] - x;
        int left = lower_bound(arr.begin(), arr.end(), l1) - arr.begin();//find first of that size
        int right = lower_bound(arr.begin(), arr.end(), l2 + 1) - arr.begin() - 1;
        left = max(left, i + 1);
        ans += max(0, (right - left + 1));
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