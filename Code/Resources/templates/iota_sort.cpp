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
	ll n, m;
	cin >> n >> m;

	vector<ll> arr(n), order(n);
	cin >> arr;

	iota(order.begin(), order.end(), 0LL);

	sort(order.begin(), order.end(), [&] (int a, int b) {
		return arr[a] < arr[b];
	});

	ll mx = 0, wins = 0;

	for (int i = 0; i < n; i++){
		if(m >= arr[order[i]])
			m -= arr[order[i]];
		else
			break;
		wins++;
	}

	for (int i = 0; i < wins; i++)
		if(order[i] != wins)
			mx = max(arr[order[i]], mx);

	ll pos = 1;
	for (int i = 0; i < n; i++)
	{
		ll cur_wins = order[i] + 1;
		if(i < wins)
			cur_wins--;
		if(cur_wins == wins + 1 && i >= wins)
		{
			if(arr[order[i]] <= (m + mx))
				cur_wins--; 
		}

		if (cur_wins > wins)
			pos++;
	}
	cout << pos;
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