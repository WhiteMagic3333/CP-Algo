#include <unordered_map>
#include <unordered_set>
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
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    ll x = 0;
    //if we have only 0
    //ans = {0}, in equal it stays 0
    //if we have only 1s
    //ans = -1, since 0 and -1 < 1 so always -1
    //if we have only -1
    //ans = 1, since 0, 1 > -1
    unordered_map<int, int> f;
    for (auto i : arr) {
        f[i]++;
    }
    vector<int> ans;
    if (f[0] == n || (f[1] > 0 && f[-1] > 0)) {
        ans.push_back(0);
    }
    if (f[1] == 0) {
        if (f[-1] > 0) {
            ans.push_back(1);
        }
    } else if (f[-1] == 0) {
        if (f[1] > 0) {
            ans.push_back(-1);
        }
    } else {
        //both greater than 1
        if (f[1] > 1) {
            ans.push_back(-1);
        }
        if (f[-1] > 1) {
            ans.push_back(1);
        }
    }
    sort(ans.begin(), ans.end());
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
    }
    return 0;
}