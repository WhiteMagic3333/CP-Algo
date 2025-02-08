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

void rec(vector<vector<int>> &ans, vector<int> &cur, int i, int n, int m) {
	if (n == 0) {
		ans.push_back(cur);
		return;
	}
	for (int j = i + 10; j + 10 * (n - 1) <= m; j++) {
		cur.push_back(j);
		rec(ans, cur, j, n - 1, m);
		cur.pop_back();
	}
}
 
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> cur;
	vector<vector<int>> ans;
	for (int i = 1; i <= 10; i++) {
		cur.push_back(i);
		rec(ans, cur, i, n - 1, m);
		cur.pop_back();
	}
	cout << ans.size() << "\n";
	for (auto &a : ans) {
		cout << a;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}