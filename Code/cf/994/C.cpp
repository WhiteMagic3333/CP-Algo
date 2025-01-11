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

int n;

void add(vector<vector<int>> &adj, int x, int y) {
	bool found = false;
	for (auto u : adj[x]) {
		if (u == y) {
			found = true;
			break;
		}
	}
	if (!found) {
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
 
void solve()
{
	int x, y;
	cin >> n >> x >> y;
	vector<vector<int>> adj_list(n + 1);
	for (int i = 1; i <= n; i++) {
		int f1 = (i - 1);
		int f2 = (i + 1);
		if (i == 1) {
			f1 = n;
		} else if (i == n) {
			f2 = 1;
		}
		adj_list[i].push_back(f1);
		adj_list[i].push_back(f2);
	}
	add(adj_list, x, y);
	vector<int> ans(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		set<int> mx;
		for (auto u : adj_list[i]) {
			mx.insert(ans[u]);
		}
		int m = 0;
		for (auto j : mx) {
			if (j == m) {
				m++;
			}
		}
		ans[i] = m;
		cout << m << " ";
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