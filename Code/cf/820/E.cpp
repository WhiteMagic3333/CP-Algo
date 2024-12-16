#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;

ll query(ll a, ll b)
{
	printf("? %lld %lld\n", a, b);
	fflush(stdout);
	ll cur;
	scanf("%lld", &cur);
	return cur;
}

void solve()
{
	for (ll i = 2; i < 26; i++)
	{
		ll d1 = query(1, i);
		ll d2 = query(i, 1);
		if(d1 != d2)
			return void(cout << "! " << d1 + d2);
		if(d1 == -1)
			return void(cout << "! " << i - 1);
	}
}

int main()
{
	solve();
	return 0;
}