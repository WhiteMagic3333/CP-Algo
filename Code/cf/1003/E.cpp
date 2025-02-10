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
	int n, m, k;
	cin >> n >> m >> k;
	if (abs(n - m) > k) {
		return void (cout << "-1");
	}
	// n zeroes
	// m ones
	// m
	// it means at any point
	// abs(n - m) <= k
	string str = "";
	int z = 0, o = 0;
	// majority is zeroes ie n
	bool found = false;
	if (n > m) {
		while(n > 0 || m > 0) {
			if (n > 0 && abs(z + 1 - o) <= k) {
				z++;
				str += '0';
				n--;
			} else if (m > 0 && abs(o + 1 - z) <= k) {
				o++;
				str += '1';
				m--;
			} else {
				return void (cout << "-1");
			}
			if (abs(z - o) == k) {
				found = true;
			}
		}
	} else {
		while(n > 0 || m > 0) {
			if (m > 0 && abs(o + 1 - z) <= k) {
				o++;
				str += '1';
				m--;
			} else if (n > 0 && abs(z + 1 - o) <= k) {
				z++;
				str += '0';
				n--;
			} else {
				return void (cout << "-1");
			}
			if (abs(z - o) == k) {
				found = true;
			}
		}
	}

	if (found) {
		cout << str;
	} else {
		cout << "-1";
	}
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