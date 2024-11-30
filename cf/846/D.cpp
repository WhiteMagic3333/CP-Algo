#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<bits/stdc++.h>
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

bool square(ll a) {
	ll r = std::sqrt(a);
    return r * r == a;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	set<ll> x;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll a = arr[i], b = arr[j];
			if (a < b)
				swap(a, b);
			ll diff = a - b;
			for (ll k = 1; k * k <= diff; k++) {
				if (diff % k == 0)
				{
					ll other = diff / k;
					if ((other + k ) % 2 == 0) {
						ll p = (other + k) / 2;
						ll _x = p * p - a;
						if (_x >= 0)
							x.insert(_x);
					}
				}
			}
		}
	}
	ll ans = 1;
	for (ll _x : x) {
		ll cur_ans = 0;
		for (int i = 0; i < n; i++){
			ll cur = _x + arr[i];
			if(square(cur))
				cur_ans++;
		}
		ans = max(ans, cur_ans);
	}
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
		cout << "\n";
	}
	return 0;
}