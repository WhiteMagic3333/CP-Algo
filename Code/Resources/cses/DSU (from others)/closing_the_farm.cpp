// https://usaco.org/index.php?page=viewproblem2&cpid=646
#include<bits/stdc++.h>
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

vector<int> parent, comp_sz;

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (comp_sz[a] < comp_sz[b]) {
            swap(a, b);
        }
        comp_sz[a] += comp_sz[b];
        parent[b] = a;
    }
}
 
void solve()
{
    freopen("closing.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent.resize(n + 1, 0);
    comp_sz.resize(n + 1, 0);
    iota(parent.begin(), parent.end(), 0LL);
    vector<int> q(n);
    cin >> q;
    vector<bool> ans;
    vector<bool> vis(n + 1, false);
    int total_comp = 0;
    for (int i = n - 1; i >= 0; i--) {
        total_comp++;
        int j = q[i];
        vis[j] = true;
        for (auto u : adj[j]) {
            if (vis[u] && find(u) != find(j)) {
                total_comp--;
                unite(u, j);
            }
        }
        ans.push_back((total_comp == 1));
    }
    reverse(ans.begin(), ans.end());
    freopen("closing.out", "w", stdout);
    for (auto i : ans) {
        cout << (i ? "YES" : "NO") << "\n";
    }
}
 
int main()
{
    solve();
    return 0;
}