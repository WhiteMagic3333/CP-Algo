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
	int q;
	cin >> q;
	vector<array<ll, 2>> arr;
	ll removed_len = 0;
	int first = 0;
	while(q--) {
		int ch;
		cin >> ch;
		if (ch == 1) {
			ll l;
			cin >> l;
			ll head = (arr.size() == 0) ? 0LL : (arr.back()[0] + arr.back()[1]);
			arr.push_back({head, l});
		} else if (ch == 2) {
			removed_len += arr[first][1];
			first++;
		} else {
			ll k;
			cin >> k;
			cout << arr[first + k - 1][0] - removed_len << '\n';
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}