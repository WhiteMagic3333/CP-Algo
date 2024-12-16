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

int cycle_length(vector<vector<int>> &adj, vector<bool> &vis, int i)
{
	vis[i] = true;
	for (int j = 0; j < adj[i].size(); j++)
	{
		if (!vis[adj[i][j]])
			return 1 + cycle_length(adj, vis, adj[i][j]);
	}
	return 1;
}

void solve()
{
	int n;
	cin >> n;
	vector<bool> vis(n + 1, false);
	vector<vector<int>> adj(n + 1);
	bool f = false;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (max(adj[a].size(), adj[b].size()) > 2 || a == b)
			f = true;
	}
	if (f)
		return void(cout << "NO");

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			int len = cycle_length(adj, vis, i);
			if (len % 2)
				return void(cout << "NO");
		}
	}
	cout << "YES";
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