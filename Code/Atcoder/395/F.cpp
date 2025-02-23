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

void dfs(vector<vector<int>> &adj, vector<int> &vis, int i, bool &found, int &nodes) {
	if (adj[i].size() == 4) {
		found = true;
	}
	if (adj[i].size() != 1 && adj[i].size() != 4) {
		nodes++;
		vis[i] = 2;
		return;
	}
	vis[i] = 1;
	nodes++;
	for (auto u : adj[i]) {
		if (vis[u] == 0) {
			dfs(adj, vis, u, found, nodes);
		} else if (vis[u] == 2) {
			nodes++;
		}
	}
	vis[i] = 2;
	return;
}
 
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> vis(n + 1, 0);
	int ans = -1;	
	for (int i = 1; i <= n; i++) {
		if (vis[i] != 2) {
			bool found = false;
			int cur = 0;
			dfs(adj, vis, i, found, cur);
			if (found) {
				ans = max(ans, cur);
			}
		}
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