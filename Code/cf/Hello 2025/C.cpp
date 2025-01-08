#include <bitset>
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

ll fun(ll l, ll r) {
	bitset<64> low(l), high(r);
	bitset<64> mid;
	for (int i = 63; i >= 0; i--) {
		if (low[i] != high[i]) {
			//highest bit differs
			//find first repeating bit
			bool found = false;
			for (int j = i - 1; j >= 0; j--) {
				if (low[j] == high[j]) {
					found = true;
					if(high[j] == 1) {
						//if both 1's then 
						mid[i] = 1;
						mid[j] = 0;
					} else {
						//both 0's
						for (int k = i - 1; k > j; k--) {
							mid[k] = low[k];
						}
						mid[j] = 1;
					}
					for (int k = j - 1; k >= 0; k--) {
						if (low[k] == high[k]) {
							if (low[k] == 1) {
								mid[k] = 0;
							} else {
								mid[k] = 1;
							}
						} else {
							mid[k] = 1;
						}
					}
					break;
				}
			}
			if (!found) {
				mid[i] = 1;
			}
			break;
		}
		mid[i] = low[i];
	}
	ll md = 0;
	for (int i = 63; i >= 0; i--) {
		md += ((1LL & mid[i]) << i);
	}
	// cout << low << '\n' << high << '\n';
	// cout << mid << '\n';
	return md;
}
 
void solve()
{
	ll l, r;
	cin >> l >> r;
	ll mid = fun(l, r);
	cout << l << ' ' << mid << ' ' << r;
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