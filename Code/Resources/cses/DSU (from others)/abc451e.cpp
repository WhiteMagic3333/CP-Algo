#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<functional>
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
    //find the lca of both, get verify
    int n;
    cin >> n;
    parent = vector<int> (n + 1);
    comp_sz = vector<int> (n + 1, 1);
    iota(parent.begin(), parent.end(), 0LL);
    vector<vector<int>> p_edges; //possible edges
    vector<vector<int>> dis(n + 1, vector<int> (n + 1, -1));
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int w;
            cin >> w;
            dis[i][j] = dis[j][i] = w;
            p_edges.push_back({w, i, j});
        }
    }
    sort(p_edges.begin(), p_edges.end());
    int total_comp = n;
    vector<vector<int>> adj(n + 1);
    for (auto edge : p_edges) {
        int u = edge[1], v = edge[2], w = edge[0];
        if (find(u) != find(v)) {
            unite(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            total_comp--;
        }
    }
    if (total_comp != 1) {
        cout << "No";
        return;
    }

    vector<int> dis_root(n + 1, 0);
    vector<ll> depth(n + 1, 0);
    vector<vector<int>> jmp(n + 5, vector<int> (21));

    std::function<void(int, int, int)> dfs = [&](int node, int p, int _dis) {
        dis_root[node] = _dis;
        depth[node] = depth[p] + 1;
        jmp[node][0] = p;
        for (auto u : adj[node]) {
            if (u != p) {
                dfs(u, node, _dis + dis[u][node]);
            }
        }
    };

    dfs(1, 0, 0);


    for (int j = 0; (1 << j) <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            jmp[i][j + 1] = jmp[jmp[i][j]][j];
        }
    }

    std::function<int(int, int)> lca = [&](int a, int b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        int depth_difference = depth[a] - depth[b];
        for (int j = 19; j >= 0; --j) {
            if ((1 << j) & depth_difference) {
                a = jmp[a][j];
            }
        }
        if (a == b) {
            return a;
        } else {
            for (int j = 19; j >= 0; --j) {
                if (jmp[a][j] != jmp[b][j]) {
                    a = jmp[a][j];
                    b = jmp[b][j];
                }
            }
            return jmp[a][0];
        }
        return -1;
    };

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int _lca = lca(i, j);
            if ((dis_root[i] + dis_root[j] - 2 * dis_root[_lca]) != dis[i][j]) {
                cout << "No";
                return;
            }            
        }
    }
    cout << "Yes";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}