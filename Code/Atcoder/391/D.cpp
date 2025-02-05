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
	int n, w;
	cin >> n >> w;
	vector<vector<int>> arr(n, vector<int> (2));
	vector<vector<array<int, 2>>> col(w + 1);
	int idx = 0;
	for (auto &row : arr) {
		cin >> row;
		col[row[0]].push_back({row[1], idx++});
	}
	int q;
	cin >> q;
	vector<vector<int>> queries(q, vector<int> (2));
	for (auto &query : queries) {
		cin >> query;
	}
	int mn_idx = n;
	for (int i = 1; i <= w; i++) {
		sort(col[i].begin(), col[i].end());
		mn_idx = min(mn_idx, (int)col[i].size());
	}
	vector<int> index(n, mn_idx + 1);
	vector<ll> time(mn_idx + 1, 1e9);
	for (int l = 1; l <= mn_idx; l++) {
		ll mx_time = 0;
		for (int i = 1; i <= w; i++) {
			index[col[i][l - 1][1]] = l - 1;
			mx_time = max(mx_time, 1LL * col[i][l - 1][0]);
		}
		time[l] = mx_time;
	}

	for (auto &que : queries) {
		que[1]--;
		if ((index[que[1]] + 1) > mn_idx) {
			cout << "Yes\n";
		} else {
			if (time[index[que[1]] + 1] > que[0]) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
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