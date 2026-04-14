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
    freopen("mootube.in", "r", stdin);
    int n, q;
    cin >> n >> q;
    parent = vector<int> (n + 1);
    comp_sz = vector<int> (n + 1, 1);
    iota(parent.begin(), parent.end(), 0LL);
    vector<vector<int>> edges(n - 1, vector<int> (3));
    for (auto &edge : edges) {
        cin >> edge[1] >> edge[2] >> edge[0];
    }
    vector<vector<int>> queries(q, vector<int> (3));
    int idx = 0;
    for (auto &q : queries) {
        cin >> q[0] >> q[1];
        q[2] = idx++;
    }
    sort(edges.begin(), edges.end(), greater<vector<int>> ());
    sort(queries.begin(), queries.end(), greater<vector<int>> ());
    vector<int> ans(q);
    int idx2 = 0;
    for (auto q : queries) {
        int k = q[0], node = q[1], idx = q[2];
        while (idx2 < edges.size() && edges[idx2][0] >= k) {
            int u = edges[idx2][1], v = edges[idx2][2];
            unite(u, v);
            idx2++;
        }
        ans[idx] = comp_sz[find(node)] - 1;
    }
    freopen("mootube.out", "w", stdout);
    for (auto i : ans) {
        cout << i << '\n';
    }
    
}
 
int main()
{
    solve();
    return 0;
}