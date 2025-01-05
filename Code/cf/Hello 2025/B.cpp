#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	cin >> arr;
	if (n == 1) {
		return void (cout << "1");
	}

	set<array<ll, 2>> s;
	map<ll, int> m;

	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
	}
	for (auto c : m) {
		s.insert({c.second, c.first});
	}
	while(s.size() && k) {
		array<ll, 2> least = *s.begin();
		if (least[0] <= k) {
			k -= least[0];
		} else {
			break;
		}
		s.erase(s.begin());
	}
	int ans = s.size();
	cout << max(ans, 1);
	
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