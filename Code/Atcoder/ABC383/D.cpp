#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<int> primes;
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
	for (ll i = 2; i <= n; i++) {
		if (prime[i]) {
			primes.push_back(i);
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


long long custom_sqrt(ll n) {
	//taking equal or smaller
	ll low = 1, high = 1e6, ans = 0;
	while (low <= high) {
		ll mid = low + (high - low) / 2LL;
		if ((mid * mid) <= n) {
			ans = max(ans, mid);
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return ans;
}

ll pow_8(ll n) {
	return n * n * n * n * n * n * n * n;
}

 
void solve()
{
	//read ioi maths for these kinds of problems



	//for N = p ^ a * q ^ b * r ^ c ...
	// where p, q, r are primes and a, b, c are whole numbers

	// No. of divisors of D(n) = (a + 1) * (b + 1) * (c + 1) ....


	// Given D(n) = 9
	// so 9 can only be made by 2 primes having power 2
	// or a single prime having power 8

	// so 
	// p1 * p1 * p2 * p2 <= N
	// p2 <= sqrt(N / p1 ^ 2)
	// lower p1 = 2
	// hence p2 <= 10^6
	ll n;
	cin >> n;
	ll ans = 0;
	ll smallest_p1 = 2; //smiles prime
	ll max_p2 = custom_sqrt(n / (smallest_p1 * smallest_p1));
	sieve(max_p2); //finding primes upto n in N(log(N)) and storing a
	// global array primes
	for (ll i = 0; i < primes.size(); i++) {
		ll p1 = primes[i];
		ll p2 = custom_sqrt(n / (p1 * p1));
		if (p1 >= p2) {
			break;
		}
		long long possible_p2s = (upper_bound(primes.begin(), primes.end(), p2) - primes.begin());
		ans += possible_p2s - 1LL - i;
		if (p1 < 38 && pow_8(p1) <= n) { //
			ans++;
		}
	}

	cout << ans;

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
 
	solve();
	return 0;
}




// 36,100,196

// 2 * 2 * 3 * 3

// 2 * 2 * 5 * 5

// 2 * 2 * 7 * 7

// N = 200

// p1 = 2 , p2 = ?

// p2 = sqrt(200 / 4) = sqrt(50) = 7.123124

// 2, 3, 5, 7