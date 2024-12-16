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

int dfs(vector<vector<int>> &adj, vector<int> &arr, int index, int &stage, int exor, vector<bool> &vis)
{
	vis[index] = true;
	int cur = arr[index];
	for (int i = 0; i < adj[index].size(); i++)
	{
		if(vis[adj[index][i]] == false){
			cur = cur ^ dfs(adj, arr, adj[index][i], stage, exor, vis);
		}
	}
	if(cur == exor)
	{
		stage++;
		cur = 0;
	}
	return cur;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1);
	vector<bool> vis(n + 1, false);
	int exor = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		exor = exor ^ arr[i];
	}
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int index;
	for (int i = 1; i <= n; i++)
	{
		if(adj[i].size() == 1)
			index = i;
	}
	if(k > 2)
	{
		int stage = 0;
		dfs(adj, arr, index, stage, exor, vis);
		if(stage > 2 || exor == 0)
			cout << "YES";
		else
			cout << "NO";
	}
	else
	{
		if(exor == 0)
			cout << "YES";
		else
			cout << "NO";	
	}
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