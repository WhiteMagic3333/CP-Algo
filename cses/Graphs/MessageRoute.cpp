#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
#include<stack>
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
 
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1, false);
	vector<int> prev(n + 1, -1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(q.size())
	{
		int cur = q.front();
		if(cur == n)
		{
			stack<int> s;
			while(cur != -1)
			{
				s.push(cur);
				cur = prev[cur];
			}
			cout << s.size() << "\n";
			while(s.size())
			{
				cout << s.top() << " ";
				s.pop();
			}
			return;
		}
		for (int i = 0; i < adj[cur].size(); i++)
		{
			if(!vis[adj[cur][i]])
			{
				q.push(adj[cur][i]);
				vis[adj[cur][i]] = true;
				prev[adj[cur][i]] = cur;
			}
		}
		q.pop();
	}
	cout << "IMPOSSIBLE";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}