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
{   //40 mins brain fog, and not going deep
    
    ll n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;

    //lets say we didnt choose the element at k
    //all after k will contribut -a[i]
    //first element will contribute +a[0]
    //all elements between 0 and k will be abs(a[i])
    vector<ll> pre(n, 0);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + abs(arr[i]);
    }

    ll suf = 0;

    ll ans = -1e18;

    for (int i = n - 1; i >= 0; i--) {
        ll left = (i == 0) ? 0 : pre[i - 1];
        ans = max(ans, left + suf);
        suf += (-1LL) * arr[i];
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