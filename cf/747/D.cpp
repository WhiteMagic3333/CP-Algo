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

int n, m;

bool assign(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &team, int cur, int t, vector<int> &travel)
{
	if (vis[cur] && team[cur] != t)
		return true;
	if (vis[cur])
		return false;
	if (cur < n + 1)
		travel.push_back(t);
	vis[cur] = true;
	team[cur] = t;
	bool ans = false;
	for (int i = 0; i < adj[cur].size(); i++)
		ans = ans | assign(adj, vis, team, adj[cur][i], t % 2 + 1, travel);
	return ans;
}

void solve()
{
	cin >> n >> m;
	vector<vector<int>> adj(n + m + 1);
	vector<bool> vis(n + m + 1, 0);
	vector<int> team(n + m + 1, 0);
	int fake = n + 1;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		string str;
		cin >> a >> b >> str;
		if (str == "imposter") {
			adj[b].push_back(a);
			adj[a].push_back(b);
		}
		else
		{
			adj[a].push_back(fake);
			adj[b].push_back(fake);
			adj[fake].push_back(a);
			adj[fake].push_back(b);
			fake++;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vector<int> travelled;
			if (assign(adj, vis, team, i, 1, travelled))
				return void(cout << "-1");
			ll ones = count(travelled.begin(), travelled.end(), 1);
			ll twos = travelled.size() - ones;
			ans += max(ones, twos);
			travelled.erase(travelled.begin(), travelled.end());
		}
	}
	cout << ans;
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