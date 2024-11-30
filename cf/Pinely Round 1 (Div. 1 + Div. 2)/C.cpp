#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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

void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<set<int>> &ans, int i)
{
	if (vis[i]) {
		return;
	}
	vis[i] = true;
	for (auto v : adj[i])
	{
		(dfs(adj, vis, ans, v));
		for (auto k : ans[v])
			ans[i].insert(k);
	}
	ans[i].insert(i);
	return;
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> adj_list(n + 1);
	vector<set<int>> ans(n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '1')
				adj_list[j].push_back(i);// j is superset of i
		}
	}
	vector<bool> vis(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(adj_list, vis, ans, i);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i].size() << " ";
		for (int j : ans[i])
			cout << j << " ";
		cout << "\n";
	}
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
	}
	return 0;
}