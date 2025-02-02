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
	int n, q;
	cin >> n >> q;
	vector<int> nest(n + 1, 1);
	vector<int> piegon(n + 1);
	iota(piegon.begin(), piegon.end(), 0);
	int ans = 0;
	int p, h, ch;
	while(q--) {
		cin >> ch;
		if (ch == 2) {
			cout << ans << "\n";
		} else {
			cin >> p >> h;
			nest[piegon[p]]--;
			if (nest[piegon[p]] == 1) {
				ans--;
			}
			piegon[p] = h;
			nest[h]++;
			if (nest[h] == 2) {
				ans++;
			}
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