#include <algorithm>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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

ll d;

bool check (multiset<ll> &s, ll i) {
    if (s.size() == 0) {
        return true;
    }
    auto it = s.lower_bound(i);
    ll high = 1e18, low = 1e18;
    if (it != s.end()) {
        high = *it;
    } 
    if (it != s.begin()) {
        it--;
        low = *it;
    }
    ll a = llabs(high - i), b = llabs(low - i);
    if (a < d || b < d) {
        return false;
    }
    return true;
}

ll sum (ll n) {
    return (n * (n + 1)) / 2;
}
 
void solve()
{
    ll n;
    cin >> n >> d;
    vector<ll> arr(n);
    cin >> arr;
    multiset<ll> s;
    ll i = 0, j = 0;
    ll ans = 0;
    while (j < n) {
        while (j < n && check(s, arr[j])) {
            s.insert(arr[j]);
            ans += (j - i + 1);
            j++;
        }
        while (i < j && !check(s, arr[j])) {
            s.erase(s.find(arr[i]));
            i++;
        }
    }
    cout << ans;
    // cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}