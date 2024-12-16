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

ll next_power(int n)
{
	ll ans = 1;
	while (ans <= n)
		ans = ans << 1LL;
	return ans;
}

void solve()
{
	int n;
	cin >> n;
	ll add = next_power(1e6);//returns min(2 ^ i) > n
	vector<int> ans;
	if(n == 3)
		return void(cout << "1 2 3\n");
	if (n % 2) {
		n--;
		ans.push_back(0);
	}
	if (n % 4 == 0) {
		for (int i = 0; i < n; i++)
			ans.push_back(i + add);
	}
	else {
		vector<ll> e, o;
		o.push_back(1);
		for (int i = 2; i <= n / 2; i++)
		{
			e.push_back(i + add - 1);
			o.push_back(i + 4 * add);
		}
		e.push_back(n / 2);
		int k = 0, j = 0;
		for (int i = 0; i < n; i++)
		{
			if (i % 2)
				ans.push_back(e[k++]);
			else
				ans.push_back(o[j++]);
		}
	}
	ll a = 0, b = 0;
	cout << ans;
	
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