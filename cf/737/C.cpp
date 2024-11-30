#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;

ll m = 1e9 + 7;

ll binpow(ll a, ll b) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	if (k == 0)
		return void(cout << '1');
	ll power = 1, ans, prev = 1, half = binpow(2, n - 1);
	ll all = (half * 2LL) % m;
	for (int i = 1; i <= k; i++)
	{
		ll equal = half, greater = 0;
		if(n % 2)
			equal = (equal + 1LL) % m;
		else
		{
			greater = 1;
			equal = (equal + m - 1LL) % m;
		}
		ans = (equal * prev) % m;
		ans = (ans + (greater * power) % m) % m;
		prev = ans;
		power = (power * all) % m;
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