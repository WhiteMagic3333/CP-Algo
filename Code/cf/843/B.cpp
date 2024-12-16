#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <map>
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
	int n;
	cin >> n;
	map<ll, ll> p;
	vector<vector<ll>> arr(n);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		arr[i].resize(k, 0);
		cin >> arr[i];
		for (int j = 0; j < k; j++)
			p[arr[i][j]]++;
	}
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if(p[arr[i][j]] < 2)
				flag = false;
		}
		if(flag)
			return void(cout << "Yes");
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