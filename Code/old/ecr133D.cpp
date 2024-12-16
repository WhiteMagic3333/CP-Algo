#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
int64_t mod = 998244353;
//here is the code
void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> all(n + 1), cur(n + 1), next(n + 1);

	for (ll i = 1; i * k <= n; i++)
	{
		ll j = i * k;
		all[j] = 1;
		cur[j] = 1;
	}
	ll sum = k;
	for (ll p = 0; sum <= n; p++)
	{
		ll i = k + 1 + p;
		sum += i;
		for (ll j = 1; j < 200001; j++)
		{
			if (cur[j] && (i + j) < 200001)
				next[i + j] = cur[j];
		}
		for (ll j = 1; j < 200001; j++)
		{
			if (next[j] && (i + j) < 200001)
				next[i + j] = (next[i + j] + next[j]) % mod;
			cur[j] = next[j];
			all[j] = (all[j] + cur[j]) % mod;
			next[j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", all[i]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}
