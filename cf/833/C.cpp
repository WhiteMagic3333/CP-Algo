#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<map>
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
	vector<ll> arr(n), sum(n);
	cin >> arr;
	vector<int> index;
	for (int i = 0; i < n; i++)
	{
		sum[i] += arr[i];
		sum[i] += (i != 0) ? sum[i - 1] : 0;
		if (arr[i] == 0)
			index.push_back(i);
	}
	index.push_back(n);
	ll ans = 0;
	for (int i = 0; i < index[0]; i++)
	{
		if(sum[i] == 0)
			ans++;
	}
	for (int i = 0; i < index.size() - 1; i++)
	{
		int start = index[i];
		int end = index[i + 1] - 1;
		// cout << start << " " << end << "\n";
		ll mx = 0;
		map<ll, ll> m;
		for (int j = start; j <= end; j++)
		{
			m[sum[j]]++;
			mx = max(mx, m[sum[j]]);
		}
		ans += mx;
		// cout << ans << "\n";
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