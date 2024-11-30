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

int n, a, b;

void dfs(vector<vector<vector<ll>>> &adj, vector<bool> &vis, ll i, map<ll, bool> &m, ll x)
{
	if(i == b && x != 0)
		return;
	if (vis[i])
		return;
	vis[i] = true;
	m[x] = true;
	for (int j = 0; j < adj[i].size(); j++)
		dfs(adj, vis, adj[i][j][0], m, x ^ adj[i][j][1]);
}

void check(vector<vector<vector<ll>>> &adj, vector<bool> &vis, ll i, map<ll, bool> &m, ll x, bool &f)
{
	if (vis[i])
		return;
	vis[i] = true;
	if (m[x] && i != b){
		f = true;
	}
	for (int j = 0; j < adj[i].size(); j++)
		check(adj, vis, adj[i][j][0], m, x ^ adj[i][j][1], f);
}

void solve()
{
	cin >> n >> a >> b;
	vector<vector<vector<ll>>> adj(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	map<ll, bool> m;
	vector<bool> vis(n + 1, false);
	dfs(adj, vis, a, m, 0);
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	bool f = false;
	check(adj, vis, b, m, 0, f);
	if (f)
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}