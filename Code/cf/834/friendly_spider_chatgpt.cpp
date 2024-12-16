#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, s, t;
vector<int> adj[N], path;
bool visited[N];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;
    path.push_back(u);
    if (u == t) return;
    for (int v : adj[u]) {
        dfs(v);
        if (path.back() == t) return;
    }
    path.pop_back();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 1; j * j <= a; j++) {
            if (a % j == 0) {
                if (j > 1) {
                    adj[i].push_back(j);
                }
                if (j * j != a) {
                    adj[i].push_back(a / j);
                }
            }
        }
    }
    cin >> s >> t;
    dfs(s);
    if (path.back() != t) {
        cout << -1 << endl;
    } else {
        cout << path.size() << endl;
        for (int u : path) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}

