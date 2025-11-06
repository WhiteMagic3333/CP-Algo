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

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> arr(n + 1, vector<int> (2));
    vector<bool> vis(n + 1,false);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        adj[arr[i][0]].push_back(i);
        adj[arr[i][1]].push_back(i);
        if (arr[i][0] == 0) {
            vis[i] = true;
            q.push(i);
        }
    }
    int ans = 0;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        ans++;
        for (auto u : adj[cur]) {
            if (!vis[u]) {
                q.push(u);
                vis[u] = true;
            }
        }
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