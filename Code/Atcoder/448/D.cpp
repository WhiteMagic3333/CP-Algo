#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <unordered_set>
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

map<int, int> m;
vector<int> ans;
vector<int> arr;
unordered_set<int> d;

void dfs(int i, vector<vector<int>> &adj, int p) {
    m[arr[i]]++;
    if (m[arr[i]] == 2) {
        d.insert(arr[i]);
    }
    if (d.size()) {
        ans[i] = 1;
    }
    for (auto &u : adj[i]) {
        if (u != p) {
            dfs(u, adj, i);
        }
    }
    m[arr[i]]--;
    if (m[arr[i]] == 1) {
        d.erase(arr[i]);
    }
}

 
void solve()
{
    int n;
    cin >> n;
    arr = vector<int> (n);
    ans = vector<int> (n, 0);
    cin >> arr;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, adj, -1);
    for (auto i : ans) {
        if (!i) {
            cout << "No";
        } else {
            cout << "Yes";
        }
        cout << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}