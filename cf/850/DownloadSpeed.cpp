#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
using namespace std;

using ll = long long;

int n, m;
ll adj[501][501];

ll flow[501];
vector<bool> V(501);
int pa[501];

bool reachable() {

	for (int i = 0; i < 501; i++)
		V[i] = false;

	queue<int> Q; Q.push(1); V[1] = 1;

	while (!Q.empty()) {

		int i = Q.front(); Q.pop();

		for (int j = 1; j <= n; j++){
			if (adj[i][j] && !V[j])
				V[j] = 1, pa[j] = i, Q.push(j);
		}
	}

	return V[n];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			adj[i][j] = 0;

	for (int i = 1; i <= m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		adj[a][b] += c;
	}
	
	int v, u;
	
	ll maxflow = 0;

	while (reachable()) {
		ll _flow = 1e18;
		for (v = n; v != 1; v = pa[v]) {
			u = pa[v];
			_flow = min(_flow, adj[u][v]);
		}
		maxflow += _flow;
		for (v = n; v != 1; v = pa[v]) {
			u = pa[v];
			adj[u][v] -= _flow;
			adj[v][u] += _flow;
		}
	}
	cout << maxflow << '\n';
}
