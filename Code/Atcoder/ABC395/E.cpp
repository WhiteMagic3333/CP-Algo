#include <queue>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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
	ll n, m, x;
	cin >> n >> m >> x;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(-u); //opposite dir
	}
	vector<bool> vis(n + 1, false);
	vector<ll> t_moves(n + 1, 1e18);
	set<array<ll, 3>> s; // total moves, cur node, cur_sign
	s.insert({0, 1, 1});
	while (s.size()) {
		ll moves = (*s.begin())[0];
		ll vertex = (*s.begin())[1];
		ll sign = (*s.begin())[2];
		s.erase(s.begin());
		vis[vertex] = true;
		for (auto &u : adj[vertex]) {
			if (!vis[abs(u)]) {
				ll _sign = u < 0 ? -1 : 1;
				u = abs(u);
				ll _moves = (sign != _sign) ? x : 0;
				_moves += moves + 1;
				if (t_moves[u] > _moves) {
					auto it = s.lower_bound({t_moves[u], u, -1});
					if (it != s.end() && (*it)[1] == u) {
						s.erase(it);
					}
					s.insert({_moves, u, _sign});
					t_moves[u] = _moves;
				}
			}
		}
	}
	s.insert({0, 1, x});
	cout << t_moves[n];

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}