#include <unordered_map>
#include <vector>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
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

void fix(vector<ll> &dp, queue<int> &q, int cur, int i) {
    q.push(i);
    while (q.size() > cur) {
        q.pop();
    }
    dp[i] = dp[i + 1];
    if (q.size() == cur) {
        dp[i] = max(dp[i], cur + dp[q.front() + 1]);
    }
}
 
void solve()
{   //16 mins, too slow
    
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    vector<queue<int>> f(n + 1);
    ll ans = 0;
    vector<ll> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        fix(dp, f[arr[i]], arr[i], i);
    }
    cout << dp[0];
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