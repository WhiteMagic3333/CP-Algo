#include <functional>
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
    vector<long long> val(n + 1, 0), indegree(n + 1, 0);
    vector<vector<array<int, 2>>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int u, v, w;
    //let 1 is the root
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        indegree[u]++;
        indegree[v]++;
    }

    long long ans = 0;

    std::function<void(int)> dfs = [&](int i) {
        if (i == 1 || indegree[i] > 1) {
            return;
        }
        indegree[i] = 0;

        for (auto& cur : adj[i]) {
            long long u = cur[0], w = cur[1];
            if (indegree[u] > 0) {
                indegree[u]--;
                val[u] += val[i];
                ans += abs(val[i]) * 1LL * w;
                dfs(u);
            }
        }

        val[i] = 0;
    };

    vector<int> leaves;
    
    for (int i = 2; i <= n; i++) {
        if (indegree[i] == 1) {
            leaves.push_back(i);
        }
    }

    for (auto i : leaves) {
        dfs(i);
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