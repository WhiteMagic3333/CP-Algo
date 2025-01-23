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

int mxd = 0, far = 0;

void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis, int d) {
	vis[i] = true;
	if (mxd < d) {
		mxd = d;
		far = i;
	}
	for (auto u : adj[i]) {
		if (!vis[u]) {
			dfs(u, adj, vis, d + 1);
		}
	}
	vis[i] = false;
}
 
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//from 1 to farthest
	vector<bool> vis(n + 1, false);
	dfs(1, adj, vis, 0);
	int cpy = far;
	dfs(cpy, adj, vis, 0);
	cout << mxd;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}