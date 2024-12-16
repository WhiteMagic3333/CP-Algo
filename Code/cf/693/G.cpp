#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
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

ll dfs(vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &ans, vector<ll> &sp, ll i)
{
	if (vis[i])
		return ans[i];
	ans[i] = sp[i];
	vis[i] = true;
	for (auto v : adj[i])
	{
		if (sp[v] < sp[i])
			ans[i] = min(ans[i], sp[v]);
		else if (sp[v] > sp[i])
			ans[i] = min(ans[i], dfs(adj, vis, ans, sp, v));
	}
	return ans[i];

}

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> adj_list(n + 1);
	vector<bool> vis(n + 1, false);
	vector<ll> sp(n + 1);
	vector<ll> ans(n + 1, 1e15);
	for (int i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
	}
	queue<array<ll, 2>> q;
	q.push({1, 0});
	vis[1] = true;
	sp[1] = 0;
	while (q.size())
	{
		ll cur = q.front()[0];
		ll dis = q.front()[1];
		q.pop();
		for (int i = 0; i < adj_list[cur].size(); i++)
		{
			if (vis[adj_list[cur][i]] == false)
			{
				q.push({adj_list[cur][i], dis + 1});
				vis[adj_list[cur][i]] = true;
				sp[adj_list[cur][i]] = dis + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	vis[1] = true;
	ans[1] = 0;
	for (ll i = 2; i <= n; i++)
	{
		if (vis[i] == false)
		{
			dfs(adj_list, vis, ans, sp, i);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
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