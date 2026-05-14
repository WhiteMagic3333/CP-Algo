#include <pthread.h>
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
{   //16 mins
    //rushed to the solution
    int n;
    cin >> n;
    vector<ll> arr(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    //all consec should be stable
    //all odd sized should also be stable
    ll ans = 0;
    for (int i = 2; i <= n; i += 2) {
        ll odd_sum = arr[i - 1] + arr[i + 1];
        ll extra = max(0LL, odd_sum - arr[i]);
        if (extra) {
            ans += extra;
            ll rem = min(extra, arr[i + 1]);
            extra -= rem;
            arr[i + 1] -= rem;
            arr[i - 1] -= extra;
        }
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