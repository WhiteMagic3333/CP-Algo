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

ll ap(ll &n) {
    //to be templated
    //also do that algo
    return (n * (n + 1)) / 2;
}
 
void solve()
{   
    //13:52 longer
    //every element is divisible by k
    // element element in a multiset will be
    // f[element] / k times
    // so as long as a subarray has lesser or equal freq
    // it is valid
    int n;
    int k;
    cin >> n >> k;
    vector<ll> arr(n);
    cin >> arr;
    vector<ll> f(n + 1, 0), times(n + 1, 0);
    for (auto i : arr) {
        f[i]++;
    }
    for (auto i : f) {
        if (i % k) {
            cout << "0";
            return;
        }
    }
    //times is freq per muliset
    for (int i = 0; i <= n; i++) {
        times[i] = f[i] / k;
    }
    int i = 0, j = 0;
    ll ans = 0;
    fill(f.begin(), f.end(), 0);
    while (j < n) {
        f[arr[j]]++;
        while (f[arr[j]] > times[arr[j]]) {
            f[arr[i]]--;
            i++;
        }
        ans += (j - i + 1LL);
        j++;
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