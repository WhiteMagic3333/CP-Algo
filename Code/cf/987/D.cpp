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
	vector<int> arr(n), pre(n);
	cin >> arr;
	pre[0] = arr[0];
	for (int i = 1; i < n; i++) {
		pre[i] = max(pre[i - 1], arr[i]);
	}
	vector<int> ans(n);
	int mn = arr[n - 1];
	ans[n - 1] = pre[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (pre[i] > mn) {
			ans[i] = ans[i + 1];
		} else {
			ans[i] = pre[i];
		}
		mn = min(mn, arr[i]);
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
	}
	return 0;
}