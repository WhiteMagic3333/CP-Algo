#include <algorithm>
#include <unordered_map>
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

ll fun(int l, int r, vector<int> &idx) {
    //how many from l and before r
    if (l > r) {
        return 0;
    }
    auto L = lower_bound(idx.begin(), idx.end(), l);
    auto R = upper_bound(idx.begin(), idx.end(), r);
    return R - L;
}
 
void solve()
{
    int n;
    cin >> n;
    ll s, x;
    cin >> s >> x;
    vector<ll> arr(n);
    cin >> arr;
    bool found = false;
    map<long long, vector<long long>> m;
    long long sum = 0, ans = 0;
    m[0].push_back(-1);
    int prev = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > x) {
            m.clear();
            sum = 0;
            found = false;
        } else {
            if (arr[i] == x) {
                found = true;
                prev = i;
            }
            if (found) {
                if (m.count(sum - s) > 0) {
                    int cnt = lower_bound(m[sum - s].begin(), m[sum - s].end(), prev) - m[sum - s].begin();
                    ans += cnt;
                }
            }
        }
        m[sum].push_back(i);
    }
    cout << ans;;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
 
    return 0;
}