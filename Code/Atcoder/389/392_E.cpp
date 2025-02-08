#include <vector>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
#include <list>
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

void dfs(vector<vector<array<int, 2>>> &adj, int i, vector<int> &vis, int sz) {
	vis[i] = sz;
	for (auto u : adj[i]) {
		if (!vis[u[0]]) {
			dfs(adj, u[0], vis, sz);
		}
	}
}

void dfs2(vector<vector<array<int, 2>>> &adj, int i, vector<bool> &vis, int parent, vector<bool> &useful) {
	vis[i] = true;
	for (auto u : adj[i]) {
		if (!vis[u[0]]) {
			dfs2(adj, u[0], vis, i, useful);
		} else if (u[0] != parent) {
			useful[i] = true;
		}
	}
}
 
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> edges;
	vector<vector<array<int, 2>>> adj(n + 1);
	vector<bool> useful(m, false);
	set<pair<int, int>> s;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges.push_back({x, y});
		adj[x].push_back({y, i + 1});
		adj[y].push_back({x, i + 1});
		if (x > y) {
			swap(x, y);
		}
		if (x == y || s.find({x, y}) != s.end()) { //self loop and repeats
			useful[i] = true;
		}
		s.insert({x, y});
	}
	vector<int> vis(n + 1, 0);
	//count components = ans
	//extra edge = self loop, cycles
	list<int> components;//first of each component
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			components.push_back(i);
			dfs(adj, i, vis, (int)components.size());
		}
	}
	//useful edges -> self loop, repeat
	vector<bool> vs(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			dfs2(adj, i, vs, 0, useful);
		}
	}
	cout << components.size() - 1 << "\n";
	for (int i = 0; i < m; i++) {
		if (useful[i]) {
			int cur_compo = vis[edges[i][0]];
			if (cur_compo != components.front()) {
				cout << i + 1 << " " << edges[i][1] << " " << components.front() << "\n";
				components.pop_front();
			} else if (cur_compo != components.back()) {
				cout << i + 1 << " " << edges[i][1] << " " << components.back() << "\n";
				components.pop_back();
			}
			if (components.size() == 1) {
				break;
			}
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}