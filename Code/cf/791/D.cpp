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

ll dfs(vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &far, int i)
{
	if(vis[i])
		return far[i] + 1;
	ll mx_far = 0;
	vis[i] = true;
	for (auto v : adj[i])
		mx_far = max(mx_far, dfs(adj,vis, far, v));
	far[i] = mx_far;
	return mx_far + 1;
}

void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> arr(n + 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i + 1];
	vector<vector<ll>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<ll> farthest(n + 1, 0);
	vector<bool> vis(n + 1, false);
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(adj, vis, farthest, i);
	}
	ll mx = *max_element(farthest.begin(), farthest.end());
	if(mx < (k - 1))
		return void(cout << "-1");
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}