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
{   //too long
    //feels dizzy and unclear
    //took 25mins
    int n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    arr.push_back(0);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            arr[i] = max(arr[i + 1], arr[i] - ans);
        }
        if (arr[i] <= arr[i + 1]) {
            ans += arr[i + 1] - (arr[i] - 1);
        }
    }
    ans += arr[0];
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