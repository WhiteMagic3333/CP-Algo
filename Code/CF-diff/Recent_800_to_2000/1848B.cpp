#include <queue>
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> c(k + 1);
    for (int i = 1; i <= n; i++) {
        int color;
        cin >> color;
        if (c[color].size() == 0) {
            c[color].push_back(0);
        }
        c[color].push_back(i);
    }
    int ans = 1e9;
    for (int i = 1; i <= k; i++) {
        c[i].push_back(n + 1);
        if (c[i].size() > 2) {
            priority_queue<int> jumps;
            for (int j = 0; j + 1 < c[i].size(); j++) {
                jumps.push(c[i][j + 1] - c[i][j] - 1);
            }
            int middle = jumps.top() - 1;
            jumps.pop();
            jumps.push(middle / 2);
            jumps.push(middle - middle / 2);
            ans = min(ans, jumps.top());
            while (jumps.empty()) {
                jumps.pop();
            }
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