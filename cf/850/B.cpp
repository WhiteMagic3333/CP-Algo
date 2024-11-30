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
	ll n, w, h;
	cin >> n >> w >> h;
	vector<ll> a(n), b(n);
	cin >> a >> b;
	ll last_end = b[n - 1];
	for (int i = 0; i < n; i++){
		a[i] += last_end + h + w;
	}
	ll shift = 0, space = 1e18;
	for (int i = 0; i < n; i++){
		ll cake_start = a[i] - shift - w;
		ll cake_end = a[i] - shift + w;
		ll pour_start = b[i] - h; 
		ll pour_end = b[i] + h;
		ll extra_shift = max(cake_start - pour_start, 0LL);
		if(cake_end < pour_end)
			return void(cout << "No");
		if(extra_shift > space)
			return void(cout << "No");
		shift += extra_shift;
		cake_end = a[i] - shift + w;
		space = min(space - extra_shift, cake_end - pour_end);
	}
	cout << "Yes";
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