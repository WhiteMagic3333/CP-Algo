#include<bits/stdc++.h>
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

int dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &kids, int cur){
	if(vis[cur])
		return kids[cur];
	for (int i = 0; i < adj[cur].size(); i++) {
		kids[cur] += 1 + dfs(adj, vis, kids, adj[cur][i]);
	}
	vis[cur] = true;
	return kids[cur];
}
 
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1, false);
	vector<int> child(n + 1, false);
	for (int i = 1; i < n; i++){
		int p;
		cin >> p;
		adj[p].push_back(i + 1);
	}
	dfs(adj, vis, child, 1);
	for (int i = 1; i <= n; i++){
		cout << child[i] << " ";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}