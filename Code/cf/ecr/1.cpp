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

 
void dfs(vector<vector<long long >> &adj, vector<bool> &vis, long long  i, long long  exp)
{
	if(vis[i] || i == exp)
		return;
	vis[i] = true;
	for (int j = 0; j < adj[i].size(); j++)
		dfs(adj, vis, adj[i][j], exp);
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<long long>> adj_list(n + 1), follower(n + 1);
	vector<bool> vis(n + 1, false);
	map<long long, long long> ref, op;
	for (long long i = 1; i <= n; i++)
	{
		long long cur;
		cin >> cur;
		ref[cur] = i;
		op[i] = cur;
	}

	long long m;
	cin >> m;
	for (long long i = 0; i < m; i++)
	{
		long long x, y;
		cin >> x >> y;
		long long a = ref[x], b = ref[y];
		// cout << a << " " << b << "\n";
		follower[b].push_back(a);
		adj_list[a].push_back(b);
	}

	long long stalker, expert;
	cin >> stalker >> expert;

	long long exp = ref[expert];

	dfs(adj_list, vis, ref[stalker], exp);

	// cout << follower[exp].size() << " ";
	bool flag = false;
	for (long long i = 0; i < follower[exp].size(); i++)
	{
		long long cur = follower[exp][i];
		if(vis[cur]){
			flag =true;
			cout << op[cur] << " ";
		}
	}
	if(falg == false)
		cout << "-1";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}