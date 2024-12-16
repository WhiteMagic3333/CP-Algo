#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef uint64_t ll;
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
	int n, q;
	cin >> n >> q;
	ll sum = 0, e = 0, o = 0;
	for (int i = 0; i < n; i++)
	{
		ll ele;
		cin >> ele;
		sum += ele;
		if(ele % 2)
			o++;
		else
			e++;
	}
	while(q--)
	{
		ll ch, add;
		cin >> ch >> add;
		if(ch == 1) // odd
		{
			sum += o * add;
			if(add % 2)
			{
				e += o;
				o = 0;
			}
		}
		else
		{
			sum += e * add;
			if(add % 2)
			{
				o += e;
				e = 0;
			}
		}
		cout << sum << "\n";
	}
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
	}
	return 0;
}