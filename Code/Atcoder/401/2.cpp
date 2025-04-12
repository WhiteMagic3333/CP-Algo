#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
using namespace std;
typedef long long ll;
const ll NMAX = 2e5 + 1;
 
vector<vector<ll>> adj;
vector<ll> v;
ll start[NMAX], finish[NMAX], timer;
 
class Fenwick {
private:
    vector<ll> bit;
    const ll n;
 
public:
    Fenwick(ll n) : n(n), bit(n + 1) {}
 
    void add(ll i, ll val) {
        while(i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }
 
    ll sum(ll i) {
        ll s = 0;
        while(i > 0) {
            s += bit[i];
            i -= (i & -i);
        }
        return s;
    }
};
 
void dfs(ll node = 1, ll par = -1) {
    start[node] = ++timer;
    for(auto child : adj[node]) {
        if(child != par) {
            dfs(child, node);
        }
    }
    finish[node] = timer;
}
 
signed main() {
    fastio
 
    ll n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    v.resize(n + 1);
    for(ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    Fenwick tree(n);
    for(ll i = 1; i <= n; i++) {
        tree.add(start[i], v[i]);
        tree.add(finish[i] + 1, -v[i]);
    }
 
    while(q--) {
        ll type, s;
        cin >> type >> s;
        if(type == 1) {
            ll x;
            cin >> x;
            ll new_val = x - v[s];
            v[s] = x;
            tree.add(start[s], new_val);
            tree.add(finish[s] + 1, -new_val);
        } else {
            cout << tree.sum(start[s]) << '\n';
        }
    }
    return 0;
}