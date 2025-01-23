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
 
void solve()
{
	//adjency matrix is used instead of adj list for floyd warshall
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> adj_matrix(n + 1, vector<ll> (n + 1, 1e18));
	vector<vector<ll>> distance(n + 1, vector<ll> (n + 1, 1e18));
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		adj_matrix[a][b] = adj_matrix[b][a] = min(c, adj_matrix[a][b]);
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			if(i == j)
				distance[i][j] = 0;
			else if(adj_matrix[i][j])
				distance[i][j] = adj_matrix[i][j];
			// else                   //if not initialized
			// 	distance[i][j] = 1e18;
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
	while(q--)
	{
		ll a, b;
		cin >> a >> b;
		if(distance[a][b] == 1e18)
			distance[a][b] = -1;
		cout << distance[a][b] << "\n";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}