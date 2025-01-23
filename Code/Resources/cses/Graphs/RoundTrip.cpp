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

bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &cycle, int index, int parent)
{
	vis[index] = true;
	cycle.push_back(index);
	for (int i = 0; i < adj[index].size(); i++)
	{
		if(!vis[adj[index][i]])
		{
			if(dfs(adj, vis, cycle, adj[index][i], index))
				return true;
		}
		else if(adj[index][i] != parent)
		{
			cycle.push_back(adj[index][i]);
			return true;
		}
	}
	cycle.pop_back();
	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1, false);
	vector<int> cycle;
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
			if (dfs(adj, vis, cycle, i, -1))
				break;
		}
	}
	if (cycle.size())
	{
		vector<int> ans;
		for (int i = cycle.size() - 1; i >= 0; i--)
		{
			ans.push_back(cycle[i]);
			if(cycle[i] == cycle.back() && ans.size() != 1)
				break;
		}
		cout << ans.size() << "\n";
		cout << ans;
	}
	else
		cout << "IMPOSSIBLE";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}