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
long long mx = 0;
int n;

void loop(vector<long long> &arr, int _i, int k, long long _xor) {

	long long cur;
	long long to_leave = k - 1;
	for (int i = _i; i < n - to_leave; i++) {
		cur = _xor ^ arr[i];
		if (k == 1) {
			mx = max(mx, cur);
		} else {
			loop(arr, i + 1, k - 1, cur);
		}
	}
}
 
void solve()
{
	int k;
	cin >> n >> k;
	vector<long long> arr(n);
	cin >> arr;
	loop(arr, 0, k, 0LL);
	// int x = 0;
	// for (int i = 0; i < 4; i++) {
	// 	x ^= arr[i];
	// }
	// cout << x;
	cout << mx;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}