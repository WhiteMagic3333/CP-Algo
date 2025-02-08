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
	ll n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	cin >> a >> b;//are upto 10^5
	//find the smallest index <= b[i]
	vector<int> mn_idx(2e5 + 5, n + 1);
	for (int i = 0; i < n; i++) {
		mn_idx[a[i]] = min(mn_idx[a[i]], i);
	}
	for (int i = 1; i <= 2e5; i++) {
		mn_idx[i] = min(mn_idx[i], mn_idx[i - 1]);
	}
	for (auto e : b) {
		if (mn_idx[e] == n + 1) {
			cout << "-1";
		} else {
			cout << mn_idx[e] + 1;
		}
		cout << '\n';
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}