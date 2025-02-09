#include <iomanip>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <unordered_map>
#include <queue>
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
	vector<unordered_map<int, int>> m(n);
	vector<int> k;
	for (int i = 0; i < n; i++) {
		int _k;
		cin >> _k;
		k.push_back(_k);
		while(_k--) {
			int cur;
			cin >> cur;
			m[i][cur]++;
		}
	}
	long double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			long double cur = 0;
			for (auto &f1 : m[i]) {
				if (m[j].count(f1.first)) {
					cur += ((1.00 * f1.second) / (1.00 * k[i])) * ((1.00 * m[j][f1.first]) / (1.00 * k[j]));
				}
			}
			ans = max(ans, cur);
		}
	}
	cout << setprecision(15) << ans;

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}