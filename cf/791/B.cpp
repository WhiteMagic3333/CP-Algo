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
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	cin >> arr;
	vector<ll> up(n, 1);
	ll update = 1;
	vector<ll> up_last(n + 1, 0);
	ll sum = accumulate(arr.begin(), arr.end(), 0LL);
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			ll index, x;
			cin >> index >> x;
			index--;
			if (up[index] != update) {
				up[index] = update;
				arr[index] = up_last[update];
			}
			ll change = x - arr[index];
			arr[index] = x;
			sum += change;
		}
		else
		{
			ll x;
			cin >> x;
			update++;
			up_last[update] = x;
			sum = n * x;
		}
		cout << sum << "\n"
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}