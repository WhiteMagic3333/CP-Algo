#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;

void sieve(ll n) {
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
std::istream& operator>>(std::istream& in, std::vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v) {
    for (const T& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
    return out;
}

vector<int> parent, blackCount, sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    blackCount[v] = 0;  // Initially no black node
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Path compression
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        blackCount[a] += blackCount[b];  // Merge black nodes count
    }
}

void toggle(int v, int c) {
    int p = find_set(v);
    // Toggle the black count: if it's black, set to white, if it's white, set to black
    blackCount[p] += (c == 0 ? 1 : -1);
}

bool hasBlackNode(int x) {
    return blackCount[find_set(x)] > 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    parent.resize(n + 1, -1);
    blackCount.resize(n + 1, 0);
    sz = vector<int>(n + 1, 0);

    vector<int> col(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {  // Type 1: Add an edge u-v
            int u, v;
            cin >> u >> v;
            union_sets(u, v);
        }
        else if (type == 2) {  // Type 2: Toggle color of node v
            int v;
            cin >> v;
            toggle(v, col[v]);
            col[v] ^= 1;
        }
        else if (type == 3) {  // Type 3: Check if there's a black node in the component of v
            int v;
            cin >> v;
            if (hasBlackNode(v)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
