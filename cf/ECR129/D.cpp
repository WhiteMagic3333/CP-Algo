#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
#include<queue>
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

int digits(ll n)
{
	int d = 0;
	while (n)
	{
		n = n / 10;
		d++;
	}
	return d;
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
		std::cout << digits(x) << ' ';
	std::cout << '\n';
	return out;
}

ll max_digit(ll n)
{
	ll ans = 0;
	while (n)
	{
		ans = max(ans, n % 10);
		n = n / 10;
	}
	return ans;
}

void solve()
{
	ll n, x;
	cin >> n >> x;
	if(digits(x) > n || ((max_digit(x) == 1 && digits(x) != n)))
		return void(cout << "-1");
	set<ll> s;
	queue<array<ll, 2>> q;
	s.insert(x);
	q.push({x, 0});
	while(q.size())
	{
		ll cur = q.front()[0];
		ll moves = q.front()[1];
		if(digits(cur) == n)
			return void(cout << moves);
		ll temp = cur;
		while(temp)
		{
			ll d = temp % 10;
			ll num = d * cur;
			if(s.find(num) == s.end())
			{
				s.insert(num);
				q.push({num, moves + 1});
			}
			temp = temp / 10;
		}
		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}