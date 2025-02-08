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

void update(vector<int> &f, vector<int> &dice) {
	for (auto num : dice) {
		f[num]++;
	}
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
	vector<int> f1(1e5 + 1, 0), f2(1e5 + 1, 0);

	priority_queue<long double, vector<long double>, greater<long double>> pq;

	for (int i = 0; i < n; i++) {
		update(f1, dice[i]);
		for (int j = i + 1; j < n; j++) {
			long double cur = 0;
			update(f2, dice[j]);
			for (int )
		}
	}

	long double ans = 0;

	while(pq.size() > 1) {
		pq.pop();
	}
	cout << setprecision(15) << pq.top();

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}