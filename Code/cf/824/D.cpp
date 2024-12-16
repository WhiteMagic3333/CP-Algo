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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> arr(n, vector<int> (k));
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> req(k, 0);
	map<vector<int>, ll> cnt;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int p = 0; p < k; p++)
				req[p] = (6 - (arr[i][p] + arr[j][p])) % 3;
			cnt[req]++;
		}
	}
	ll ans = 0;
	for (auto i : arr)
		ans += ((cnt[i] * (cnt[i] - 1)) / 2LL);
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}