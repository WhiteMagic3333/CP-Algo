#include <algorithm>
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
	vector<int> a(n), b_fake(m);
	cin >> a >> b_fake;
	vector<int> b(m);
	int mn = b_fake[0];
	for (auto e : b_fake) {
		mn = min(e, mn);
	}
	for (int i = 0; i < m; i++) {
		if (b_fake[i] == mn) {
			for (int j = 0; j < m; j++) {
				b[j] = b_fake[(i + j) % m];
			}
			break;
		}
	}
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			a[i] = min(a[i], b[0]);
		}
	} else {
		for (int i = 0; i < n; i++) {
		int rem = n - i;
		if (rem > m) {
			if (a[i] > b[0]) {
				int j = i;
				while(rem > m) {
					a[j] = b[0];
					j++;
					rem = n - j;
				}
				int k = 0;
				while(j < n) {
					a[j] = b[k];
					j++, k++;
				}
				break;
			}
		} else if (rem == m) {
			for (int j = 0; j < m; j++) {
				if (a[i + j] < b[j]) {
					break;
				} else if (a[i + j] > b[j]) {
					for (int k = j; k < m; k++) {
						a[i + k] = b[k];
					}
					break;
				}
			}
		}
	}
	}
	cout << a;
	//rotate b till its min
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