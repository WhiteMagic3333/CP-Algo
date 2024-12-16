#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

ll a[N];

ll cal(ll n) {
	ll ans = 0;
	for (ll i = n; i >= 3; i--) {
		ans = max(ans, abs(a[1] - a[i]) + abs(a[i] - a[i - 1]));
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		for (ll i = 1; i <= n; i++) cin >> a[i];
		ll ans = 0;
		sort(a + 1, a + 1 + n);
		ans = max(ans, cal(n));
		for (ll i = 1; i <= n; i++) a[i] = -a[i];
		sort(a + 1, a + 1 + n);
		ans = max(ans, cal(n));
		cout << ans << endl;
	}
}