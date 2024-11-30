// Bipartite Graph

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
	for (int i = 1; i < v.size(); i++)
		cout << v[i] << " ";
	std::cout << '\n';
	return out;
}

bool assign(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &team, int cur, int t)
{
	if (vis[cur] && team[cur] != t)
		return true;
	if (vis[cur])
		return false;
	vis[cur] = true;
	team[cur] = t;
	bool ans = false;
	for (int i = 0; i < adj[cur].size(); i++)
		ans = ans | assign(adj, vis, team, adj[cur][i], t % 2 + 1);
	return ans;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1, false);
	vector<int> team(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (assign(adj, vis, team, i, 1))
				return void(cout << "IMPOSSIBLE");
		}
	}
	cout << team;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}