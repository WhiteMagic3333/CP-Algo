#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
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
	vector<vector<array<ll, 2>>> adj(n + 1); // {c, a, b} a -> b, (cost->c)
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	vector<ll> cost(n + 1, 1e18);
	priority_queue<array<ll, 3>> s;//{cost_to_reach_that_city, city, max_cost_of_flight }
	s.push({0, 1, 0});
	while (s.size()) {
		ll cur_sum = s.top()[0] * (-1);
		ll cur_city = s.top()[1];
		ll cur_max_flight_cost = s.top()[2];
		s.pop();
		ll cur_cost = cur_sum - cur_max_flight_cost + (cur_max_flight_cost / 2);
		if(cur_cost < cost[cur_city]) {
			cost[cur_city] = cur_cost;
			for (int i = 0; i < adj[cur_city].size(); i++) {
				ll flight_cost = adj[cur_city][i][0];
				ll next_city = adj[cur_city][i][1];
				s.push({(cur_sum + flight_cost) * (-1), next_city, max(cur_max_flight_cost, flight_cost)});
			}
		}
	}
	cout << cost[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}