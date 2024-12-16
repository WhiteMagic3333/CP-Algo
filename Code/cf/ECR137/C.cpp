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
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> arr(n);
	cin >> arr;
	vector<vector<ll>> dp(n, vector<ll> (2, 0));
	if(str[0] == '1')
		dp[0][0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		if(str[i] == '1')
		{
			ll prev = (i == 1) ? 0 : max({dp[i - 2][0], dp[i - 2][1], dp[i - 1][1]});
			dp[i][0] = arr[i] + max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = arr[i - 1] + prev;
		}
		else
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]); 
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