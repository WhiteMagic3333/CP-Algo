#include <iomanip>
#include <queue>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <map>
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
	vector<vector<int>> dice(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		while(k--) {
			int cur;
			cin >> cur;
			dice[i].push_back(cur);
		}
	}
	vector<int> freq(1e5 + 1, 0);

	map<int, priority_queue<long double, vector<long double>, greater<long double>>> m;

	for (int i = 0; i < n; i++) {
		int sz = dice[i].size();
		for (int j = 0; j < sz; j++) {
			freq[dice[i][j]]++;
		}
		for (int i = 1; i < 1e5 + 1; i++) {
			if (freq[i]) {
				long double prob = freq[i] / (1.00 * sz);
				m[i].push(prob);
			}
			freq[i] = 0;
		}
	}

	long double ans = 0;

	for (int i = 1; i <= 1e5; i++) {
		if (m[i].size() > 1) {
			while(m[i].size() > 2) {
				m[i].pop();
			}
			long double cur = m[i].top();
			m[i].pop();
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