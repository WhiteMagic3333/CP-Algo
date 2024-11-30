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
 
void fun(int n, int m, vector<vector<array<ll, 2>>> &flight, vector<ll> &distance, vector<bool> &processed)
{
	// int n, m;
	// cin >> n >> m;
	// vector<vector<array<ll, 2>>> flight(n + 1);
	// vector<ll> distance(n + 1, 1e18);
	// vector<bool> processed(n + 1, false);
	// for (int i = 0; i < m; i++)
	// {
	// 	ll a, b, c;
	// 	cin >> a >> b >> c;
	// 	flight[a].push_back({b, c});
	// }
	set<array<ll, 2>> s;//at distance 0 we have 1
	s.insert({0, 1});
	distance[1] = 0;
	while(s.size())
	{
		ll city = (*s.begin())[1];
		ll cur_distance = (*s.begin())[0];
		s.erase(s.begin());
		if(processed[city])
			continue;
		processed[city] = true;
		for (auto u : flight[city])
		{
			ll destination = u[0];
			ll flight_distance = u[1];
			if(cur_distance + flight_distance < distance[destination])
			{
				distance[destination] = cur_distance + flight_distance;
				s.insert({distance[destination], destination});
			}
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	cout << distance[i] << " ";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}