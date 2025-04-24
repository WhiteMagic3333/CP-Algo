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

ll fun(vector<ll> &arr, vector<vector<vector<ll>>> &dp, vector<vector<vector<bool>>> &vis, ll i, ll j, ll rem, ll d)
{
	if (vis[i][j][rem])
		return dp[i][j][rem];
	if (j == 0 && rem == 0)
		return dp[i][j][rem] = 0;
	ll cur = -1;
	for (ll index = 0; index < i; index++)
	{
		for (ll taken = 0; taken <= min(j - 1, i + 1); taken++)
		{
			for (ll k = 0; k < arr.size(); k++)
			{
				if ((k + arr[i]) % d == rem) {
					fun(arr, dp, vis, index, taken, k, d);
					if (dp[index][taken][k] != -1){
						cur = max(cur, dp[index][taken][k] + (k + arr[i]) / d);
					}
				}
			}
		}
	}
	vis[i][j][rem] = true;
	dp[i][j][rem] = cur;
	return dp[i][j][rem];
}

void solve()
{
	ll k, n, d;
	cin >> n >> k >> d;
	vector<ll> arr(n);
	cin >> arr;
	//a[i] = a[i] % d + (a[i] / d) * d
	//dp[i][j][k] = (sum) / d when remainder is k
	//till, the i'th index we have taken j elements
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>> (n + 1, vector<ll> (n + 1, -1)));
	vector<vector<vector<bool>>> vis(n + 1, vector<vector<bool>> (n + 1, vector<bool> (n + 1, false)));
	// cout << dp[n - 1][k][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}