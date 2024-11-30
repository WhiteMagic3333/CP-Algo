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
		std::cout << x << '_';
	std::cout << '\n';
	return out;
}

void debug()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	cout << n << "_";
	cout << arr;
}

void solve()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll gc = 0;
	for (int i = 0; i < n; i++)
		gc = __gcd(gc, arr[i]);
	if (gc == 1)
		return void(cout << 0);
	gc = 0;
	for (int i = 0; i < n - 1; i++)
		gc = __gcd(gc, arr[i]);
	if (__gcd(gc, __gcd(n, arr[n - 1])) == 1)
		return void(cout << 1);
	gc = 0;
	for (int i = 0; i < n - 2; i++)
		gc = __gcd(gc, arr[i]);
	gc = __gcd(gc, arr[n - 1]);
	if (__gcd(gc, __gcd(arr[n - 2], n - 1)) == 1)
		return void(cout << 2);
	cout << 3;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve();
		cout << "\n";
	}
	return 0;
}