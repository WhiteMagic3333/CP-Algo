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
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	cin >> a >> b;
	sort(b.begin(), b.end());
	a[0] = min(a[0], b[0] - a[0]);
	// so 
	// a[i - 1] <= (b[j] - a[i], a[i]);
	// a[i - 1] + a[i] <= b[j]
	for (int i = 1; i < n; i++) {
		//smallest to make
		auto oth = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
		ll bj = a[i];
		if (oth != b.end()) {
			bj = *oth - a[i];
		}
		if (a[i] >= a[i - 1]) {
			a[i] = min(a[i], bj);
		} else {
			a[i] = bj;
		}
	}
	bool valid = true;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			valid = false;
		}
	}
	if (valid) {
		cout << "Yes";
	} else {
		cout << "No";
	}
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