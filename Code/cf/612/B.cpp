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

bool is_greater(string &a, string &b, int k)
{
	for (int i = 0; i < k; i++)
	{
		if (a[i] > b[i])
			return true;
		else if (a[i] < b[i])
			return false;
	}
	return false;
}

string extract(string &a, string &b, int k)
{
	string str(k, ' ');
	for (int i = 0; i < k; i++)
	{
		if (a[i] == b[i])
			str[i] = a[i];
		else
			str[i] = 'S' ^ 'E' ^ 'T' ^ a[i] ^ b[i];
	}
	return str;
}

void solve()
{
	int n, K;
	cin >> n >> K;
	map<string, ll> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		m[str]++;
	}
	ll ans = 0;
	vector<string> v;
	for (auto p : m)
	{
		v.push_back(p.first);
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			string req = extract(v[i], v[j], K);
			if (is_greater(req, v[j], K))
			{
				ans += m[v[i]] * m[v[j]] * m[req];
			}
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