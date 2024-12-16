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

void fun(vector<vector<int>> &graph, vector<array<int, 2>> &range, vector<bool> &vis, vector<bool> &temp_vis, vector<array<ll, 2>> &dp, int i)
{
	if (vis[i])
		return;
	vis[i] = true;
	temp_vis[i] = true;
	for (int j = 0; j < graph[i].size(); j++)
	{
		if (vis[graph[i][j]] == false)
			fun(graph, range, vis, temp_vis, dp, graph[i][j]);
	}
	for (int j = 0; j < graph[i].size(); j++)
	{
		if (!temp_vis[graph[i][j]]) {
			dp[i][0] += max(dp[graph[i][j]][0] + abs(range[graph[i][j]][0] - range[i][0]), dp[graph[i][j]][1] + abs(range[graph[i][j]][1] - range[i][0]));
			dp[i][1] += max(dp[graph[i][j]][0] + abs(range[graph[i][j]][0] - range[i][1]), dp[graph[i][j]][1] + abs(range[graph[i][j]][1] - range[i][1]));
		}
	}
	temp_vis[i] = false;
}

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 2>> range(n + 1);
	vector<array<ll, 2>> dp(n + 1);
	vector<bool> vis(n + 1, false), temp_vis(n + 1, false);
	vector<vector<int>> graph(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> range[i][0] >> range[i][1];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int start = -1;
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1) {
			start = i;
			break;
		}
	}
	fun(graph, range, vis, temp_vis, dp, start);
	cout << max(dp[start][0], dp[start][1]);
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