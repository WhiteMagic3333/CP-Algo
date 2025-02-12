#include <queue>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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
	//zero is imp
	int n;
	cin >> n;
	vector<int> arr(n), mn(n, 2e9), _mex(n + 1, 0);
	vector<bool> valid(n + 1, false);
	cin >> arr;
	mn[0] = arr[0] == 0 ? 2e9 : arr[0];
	int ans = arr[0] != 0;
	for (int i = 1; i < n; i++) {
		if (arr[i]) {
			mn[i] = min(mn[i - 1], arr[i]);
			ans++;
		} else {
			mn[i] = mn[i - 1];
		}
	}
	int mex = 1;
	set<int> s;
	for (int i = n - 1; i >= 0; i--) {
		s.insert(arr[i]);
		while(s.find(mex) != s.end()) {
			mex++;
		}
		_mex[i] = mex;
	}

	for (int i = 0; i < n; i++) {
		if (mn[i] >= _mex[i + 1]) {
			valid[i] = true;
			if (i != 0) {
				valid[i] = valid[i] && valid[i - 1];
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 0 && mn[i] >= _mex[i + 1] && (i == 0 || valid[i - 1])) {
			ans++;
			break;
		}
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