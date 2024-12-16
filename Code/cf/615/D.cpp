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
	ll q, x;
	cin >> q >> x;
	vector<ll> freq(x, 0);
	set<array<ll, 2>> s;
	for (int i = 0; i < x; i++)
		s.insert({0, i});
	ll mex;
	while(q--)
	{
		ll element;
		cin >> element;
		element = element % x;
		s.erase({freq[element], element});
		freq[element]++;
		s.insert({freq[element], element});
		mex = (*s.begin())[1];
		mex = mex + freq[mex] * x;
		cout << mex << "\n";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}