#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
vector<ll> primes;
vector<bool> semi_primes;
map<ll, array<ll, 2>> factor;
 
void sieve(ll n)
{
	prime.resize(n + 1, true);
	semi_primes.resize(n + 1, false);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (prime[i] && i * i <= n) {
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
		if (prime[i]) {
			primes.push_back(i);
		}
	}
	int cnt = 0;
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i] * primes[i] > n) {
			break;
		}
		for (int j = i; j < primes.size(); j++) {
			if ((primes[i] * primes[j]) > n) {
				break;
			}
			semi_primes[primes[i] * primes[j]] = true;
			factor[primes[i] * primes[j]] = {primes[i], primes[j]};
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
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	//semi prime = no. of factors = 3
	// because
	/*
		if num is prime
			then ans += distinct primes_before other than this

		if num has three factors i,e prod of two primes
	*/
	ll tpf = 0;//total_prime_frequency
	ll ans = 0;
	map<ll, ll> freq;
	map<ll, ll> semi_primes_factor_pres;
	for (int i = 0; i < n; i++) {
		if (prime[arr[i]]) {
			freq[arr[i]]++;
			tpf++;
			ans += (tpf - freq[arr[i]]);
			ans += semi_primes_factor_pres[arr[i]]; // all semi primes which are its factor
		} else if (semi_primes[arr[i]]) {
			freq[arr[i]]++;
			ans += freq[arr[i]];
			ans += freq[factor[arr[i]][0]];
			semi_primes_factor_pres[factor[arr[i]][0]]++;
			if (factor[arr[i]][0] != factor[arr[i]][1]) {
				ans += freq[factor[arr[i]][1]];
				semi_primes_factor_pres[factor[arr[i]][1]]++;
			}
		}
	}
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
 	sieve(3e5 + 5);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}