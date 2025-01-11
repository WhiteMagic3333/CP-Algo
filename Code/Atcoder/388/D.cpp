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
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	multiset<ll> given_to;
	for (int i = 0; i < n; i++) {
		arr[i] += given_to.size();
		while(given_to.size() && (*(given_to.begin()) <= i)) {
			given_to.erase(given_to.begin());
		}
		if (arr[i]) {
			given_to.insert(i + arr[i]);
		}
		arr[i] = arr[i] - min((n - i - 1) * 1LL, arr[i]);
	}
	cout << arr;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}