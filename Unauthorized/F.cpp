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
	int q;
	cin >> q;
	vector<ll> s(26, 0), t(26, 0);
	s[0] = t[0] = 1;
	while (q--)
	{
		vector<ll> x(26, 0);
		ll d, k;
		cin >> d >> k;
		string str;
		cin >> str;
		ll n = str.length();
		for (int i = 0; i < n; i++) {
			x[str[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (d == 1)
				s[i] += x[i] * k;
			else
				t[i] += x[i] * k;
		}
		/*
		*/
		bool tf = false, sf = false;
		for (int j = 1; j < 26; j++){
			if(t[j])
				tf = true;
			if(s[j])
				sf = true;
		}
		if(s[0] < t[0] && sf == false)
			tf = true;
		if (tf)
			cout << "YES\n";
		else
			cout << "NO\n";
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