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

bool path(vector<vector<array<ll, 2>>> &adj_list, ll cur, ll index, vector<bool> &vis)
{
	if (cur == index)
		return true;
	if (vis[cur])
		return false;
	vis[cur] = true;
	for (auto u : adj_list[cur])
	{
		ll next_room = u[0];
		if (path(adj_list, next_room, index, vis))
			return true;
	}
	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<array<ll, 3>> edge_list;
	vector<vector<array<ll, 2>>> adj_list(n + 1);
	vector<ll> score(n + 1, 1e18);
	vector<bool> vis(n + 1, false);
	vector<bool> v1(n + 1), v2(n + 1);
	for (int i = 0; i < m; i++)
	{
		ll a, b, x;
		cin >> a >> b >> x;
		edge_list.push_back({a, b, -1LL * x});
		adj_list[a].push_back({b, -1LL * x});
	}
	score[1] = 0;
	// cout << score;
	vector<ll> suspects;
	for (int i = 1; i <= n; i++)
	{
		for (auto u : edge_list)
		{
			ll a = u[0];
			ll b = u[1];
			ll gained_score = u[2];
			if (score[b] > score[a] + gained_score)
			{
				score[b] = score[a] + gained_score;
				if (i == n)
					suspects.push_back(b);
			}
		}
		// cout << score;
	}
	// cout << suspects;
	for (int i = 0; i < suspects.size(); i++)
	{
		v1 = v2 = vis;
		if (path(adj_list, 1, suspects[i], v1) && path(adj_list, suspects[i], n, v2))
			return void(cout << "-1");
	}
	cout << -score[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}