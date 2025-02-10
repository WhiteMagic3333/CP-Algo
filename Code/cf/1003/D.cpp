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
	vector<vector<ll>> arr(n, vector<ll> (m, 0));
	vector<pair<ll, int>> score_index;
	int idx = 0;
	for (auto &a : arr) {
		ll sum = 0;
		for (auto &cur : a) {
			cin >> cur;
			sum += cur;
		}
		score_index.push_back({sum, idx++});
	}
	sort(score_index.begin(), score_index.end());
	ll score = 0, sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		idx = score_index[i].second;
		for (int j = 0; j < m; j++) {
			sum += arr[idx][j];
			score += sum;
		}
	}
	cout << score;
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