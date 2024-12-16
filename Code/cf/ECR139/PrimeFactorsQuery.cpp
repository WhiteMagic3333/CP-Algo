/*

This is to find all the prime factors of a number in log(N)
time per query
Seive generates the largest prime factor for each number
which takes O(sqrt(n) * (log(N))) time complexity
*/

#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;

vector<ll> lpf(1e7 + 1, 0);//largest prime factor of i

void sieve(ll n)
{
	prime.resize(n + 1, true);
	for (ll i = 2; i * i <= n; i++) {
		if (prime[i]) {
			lpf[i] = i;
			for (ll j = i * i; j <= n; j += i) {
				prime[j] = false;
				lpf[j] = i;
			}
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
	int q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		vector<ll> prime_factors;
		while (n != 1)
		{
			if (lpf[n] == 0)
				lpf[n] = n;
			ll cur = lpf[n];
			prime_factors.push_back(cur);
			while (n % cur == 0)
				n = n / cur;
		}
		cout << prime_factors;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(1e7);
	solve();
	return 0;
}