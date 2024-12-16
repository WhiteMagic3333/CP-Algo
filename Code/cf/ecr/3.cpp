#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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

void fun(ll n, ll m, vector<vector<array<ll, 2>>> &flight, ll a, ll b)
{
	// int n, m;
	// cin >> n >> m;
	// vector<vector<array<ll, 2>>> flight(n + 1);
	// for (int i = 0; i < m; i++)
	// {
	// 	ll a, b, c;
	// 	cin >> a >> b >> c;
	// 	flight[a].push_back({b, c});
	// }
	vector<ll> distance(n + 1, 1e15);
	vector<bool> processed(n + 1, false);
	set<array<ll, 2>> s;//at distance 0 we have city 1
	s.insert({0, a});
	distance[a] = 0;
	while (s.size())
	{
		ll city = (*s.begin())[1];
		ll cur_distance = (*s.begin())[0];
		s.erase(s.begin());
		if (processed[city])
			continue;
		processed[city] = true;
		for (auto u : flight[city])
		{
			ll destination = u[0];
			ll flight_distance = u[1];
			if (cur_distance + flight_distance < distance[destination])
			{
				distance[destination] = cur_distance + flight_distance;
				s.insert({distance[destination], destination});
			}
		}
	}
	if (distance[b] != 1e18)
		cout << distance[b];
	else
		cout << "-1";
}

void solve()
{
	long long n;
	cin >> n;
	vector<vector<array<ll, 2>>> adj_list(n + 1);
	map<long long, long long> ref, op;
	for (int i = 1; i <= n; i++)
	{
		int cur;
		cin >> cur;
		ref[cur] = i;
		op[i] = cur;
	}
	long long m;
	cin >> m;
	for (long long i = 0; i < m; i++)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		long long a = ref[x], b = ref[y];
		adj_list[a].push_back({b, z});
	}

	long long follower, following;
	cin >> follower >> following;

	fun(n, m, adj_list, ref[follower], ref[following]);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}