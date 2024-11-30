//3542
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

int dfs(vector<vector<int>> &adj, vector<int> &arr, int &c, int &exor, int index, vector<bool> &vis)
{
	vis[index] = true;
	int cur = arr[index];
	for (int i = 0; i < adj[index].size(); i++)
	{
		if (vis[adj[index][i]] == false)
		{
			vis[adj[index][i]] = true;
			cur = cur ^ dfs(adj, arr, c, exor, adj[index][i], vis);
		}
	}
	if (cur == 0)
		c++;
	cout << cur << " ";
	return cur;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1);
	int exor = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		exor ^= arr[i];
	}
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int index = -1;
	for (int i = 1; i <= n; i++)
	{
		if(adj[i].size() < 2)
		{
			index = i;
		}
	}
	cout << exor << "\n";
	int count = 0;
	dfs(adj, arr, count, exor, 1, vis);
	cout << count;
	if (count > 1)
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