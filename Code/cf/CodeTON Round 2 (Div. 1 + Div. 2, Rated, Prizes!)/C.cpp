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
	vector<ll> arr(m);
	cin >> arr;
	sort(arr.begin(), arr.end());
	vector<ll> len;
	for (int i = 0; i < m - 1; i++)
	{
		ll cur = arr[i + 1] - arr[i] - 1;
		if (cur)
			len.push_back(cur);
	}
	if(m == 1)
		len.push_back(n - 1);
	else
		len.push_back(n - arr.back() + arr[0] - 1);
	sort(len.begin(), len.end(), greater<ll>());
	ll ans = 0;
	ll cur = 0;
	int i = 0;
	// cout << len;
	while(i < len.size() && len[i] > cur)
	{
		ll cur_len = len[i] - cur;
		if(cur_len > 1)
		{
			cur += 4;
			ans += cur_len - 1;
		}
		else if(cur_len == 1)
		{
			ans++;
			cur += 2;
		}
		i++;
		// cout << ans << " ";
	}
	cout << n - ans;
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