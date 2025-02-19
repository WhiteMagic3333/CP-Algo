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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	cin >> arr;
	int m = *max_element(arr.begin(), arr.end());
	vector<int> freq(m + 1, 0);
	vector<int> div_by(m + 1, 0), ans(m + 1, 0);
	for (auto i : arr) {
		freq[i]++;
	}
	//total numbers divisible by
	for (int i = 1; i <= m; i++) {
		for (int d = i; d <= m; d += i) {
			div_by[i] += freq[d];
		}
	}
	for (int i = 1; i <= m; i++) {
		if (div_by[i] < k) {
			continue;
		}
		for (int d = i; d <= m; d += i) {
			ans[d] = i;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[arr[i]] << "\n";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}