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
	ll q;
	cin >> q;
	while (q--)
	{
		ll n, k;
		cin >> n >> k;
		//pk - r
		if (k <= n / 2) {
			cout << k * 2 << "\n";
			continue;
		}
		ll deleted = n / 2;
		ll inside = n - deleted;
		k = k - deleted;
		ll p = 4, r = 1;
		bool first = false;
		if(n % 2 == 1)
			first = true;
		while (1)
		{
			if(first)
			{
				if(inside % 2)
				{
					deleted = inside / 2 + 1;
					first = false;
				}
				else {
					deleted = inside / 2;
				}
				r = p - r;
			}
			else
			{
				r = (p / 2) - r;
				deleted = inside / 2;
				if(inside % 2) {
					first = true;
				}
			}
			cout << p << "n - " << r << "\n";
			if(k <= deleted)
			{
				cout << p * k - r << "\n";
				break;
			}
			p = p * 2;
			inside = inside - deleted;
			k = k - deleted;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}