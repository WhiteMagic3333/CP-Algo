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
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			ans += arr[i];
	}
	//first
	set<ll> cur;
	cur.insert(0);
	ll even = 0, odd = 0;
	ll mx = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			even += arr[i];
		else{
			odd += arr[i];
			ll cur_diff = odd - even;
			ll mn = *cur.begin();
			mx = max(mx, cur_diff - mn);
			cur.insert(cur_diff);
		}
	}
	cur.clear();
	even = odd = 0;
	cur.insert(0);
	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 0){
			even += arr[i];
			ll cur_diff = odd - even;
			ll mn = *cur.begin();
			mx = max(mx, cur_diff - mn);
			cur.insert(cur_diff);
		}
		else
			odd += arr[i];
	}
	cout << ans + mx;
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