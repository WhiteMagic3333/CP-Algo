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
 
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> arr(n);
    cin >> arr;
    for (auto &i : arr) {
        i = i % k;
    }
    sort(arr.begin(), arr.end());
    //so any element i can be max
    multiset<long long> s;
    for (auto i : arr) {
        s.insert(i);
    }
    ll ans = (*s.rbegin() - *s.begin());
    int N = 3 * n;
    while (N--) {
        ll first = *s.begin();
        s.erase(s.find(first));
        s.insert(k + first);
        ll cur = (*s.rbegin() - *s.begin());
        ans = min(ans, cur);
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