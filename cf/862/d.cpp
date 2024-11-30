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
 
void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis){
	if(vis[i])
		return ;
	vis[i] = true;
	for (auto u : adj[i])
		dfs(u, adj, vis);
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int comp = 0;
	for (int i = 1; i <= n; i++){
		if(!vis[i]){
			comp++;
			dfs(i, adj, vis);
		}
	}
	cout << comp;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}