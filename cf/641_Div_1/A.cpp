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

ll lcm(ll a, ll b)
{
	ll g = __gcd(a, b);
	ll _lcm = (a * b) / g;
	return _lcm;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll g = lcm(arr[0], arr[1]);
	ll prev = __gcd(arr[0], arr[1]);
	for (int i = 2; i < n; i++)
	{
		ll second = prev * arr[i] / __gcd(prev, arr[i]);
		g = __gcd(g, second);
		prev= __gcd(prev, arr[i]);
	}
	cout << g;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}