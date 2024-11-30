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
	ll n, k;
	cin >> n >> k;
	/*
	y = (n - 2x) / k;
	if(n - 2x) % y == 0;
	*/
	if(n % 2 == 0 || n % k == 0)
		return void(cout << "Yes");
	else if ((n % 2) == (k % 2) && n >= k) //n-2 >= k && both have same parity
		return void(cout << "Yes");
	else if ((n % 2) != (k % 2)) {
		//different parity
		if (n % 2 == 0) { //so k is odd
			if (n >= (2 * k))
				return void(cout << "Yes");
		}
	}
	cout << "No";
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