#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
using namespace std;
typedef long long ll;
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
ll mod = 1e9 + 7;
vector<ll> dp(2e5 + 11, 0), ones(2e5 + 11, 0);
vector<bool> vis(2e5 + 11, false);

void pre()
{
	dp[0] = 1;
	ones[1] = 1;
	vis[1] = true;
	vis[0] = true;
	queue<ll> q;
	q.push(1);
	while (q.size())
	{
		ll index = q.front();
		if(index < 2e5 + 1)
		{
			ones[index + 9] = (ones[index + 9] + ones[index]) % mod;
			ones[index + 10] = (ones[index + 10] + ones[index]) % mod;
			dp[index + 9] = (dp[index + 9] + ones[index]) % mod;
			if(!vis[index + 9])
			{
				vis[index + 9] = true;
				q.push(index + 9);
			}
			if(!vis[index + 10])
			{
				vis[index + 10] = true;
				q.push(index + 10);
			}
		}
		q.pop();
	}
	for (int i = 1; i < 2e5 + 11; i ++ )
	{
		dp[i] = (dp[i - 1] + dp[i]) % mod;
	}
}

void solve()
{
	string n;
	ll m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 0; i < n.length(); i++)
	{
		int d =  (n[i] - '0');
		ans = (ans + dp[m + d]) % mod;
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}