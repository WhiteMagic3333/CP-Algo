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

bool ok(vector<ll> &arr) {
    ll mn = 1e9, mx = -1e9;
    int n = arr.size(), neg = 0;
    for (auto i : arr) {
        mx = max(i, mx);
        mn = min(i, mn);
        neg += i < 0;
    }
    if (neg == 0) {
        return false;
    }
    bool all_same_abs = true;
    for (auto i : arr) {
        if (abs(i) != abs(mx) || abs(i) != abs(mn)) {
            all_same_abs = false;
        }
    }
    if (all_same_abs) {
        if (neg == n ||neg == n / 2 || (n % 2 == 1 && (n / 2) + 1 == neg)) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        return true;
    }
    return false;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end(), [&] (ll a, ll b) {
        return abs(a) < abs(b);
    });
    if (ok(arr)) {
        return;
    }
    //while sorting make sure that alternating signs appear
    for (int i = 1; i < n - 1; i++) {
        ll f = arr[i] * arr[i];
        ll s = arr[i - 1] * arr[i + 1];
        if (f != s) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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