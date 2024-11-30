#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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
	multiset<int> a;
	multiset<int, greater<int>> b;
	for (int i = 0; i < n; i++)
	{
		int cur;
		cin >> cur;
		while(cur % 2 == 0)
			cur = cur / 2;
		a.insert(cur);
	}
	for (int i = 0; i < n; i++)
	{
		int cur;
		cin >> cur;
		b.insert(cur);
	}
	while(b.size())
	{
		auto p = b.begin();
		ll cur = *p;
		while(cur && a.find(cur) == a.end())
		{
			cur = cur / 2;
		}
		if(cur == 0)
			return void(cout << "NO");
		b.erase(p);
		auto q = a.find(cur);
		a.erase(q);
	}
	cout << "YES";
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