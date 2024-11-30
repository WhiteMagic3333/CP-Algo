#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <map>
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
	vector<vector<int>> arr(n, vector<int> (m));
	map<vector<int>, int> ma;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		vector<int> idx(m + 1, 0), cur;
		for (int j = 0; j < m; j++) {
			idx[arr[i][j]] = j + 1;
		}
		for (int j = 1; j <= m; j++) {
			cur.push_back(idx[j]);
			ma[cur]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int ans = 0;
		vector<int> cur;
		for (int j = 0; j < m; j++) {
			cur.push_back(arr[i][j]);
			if (ma[cur])
				ans = max(ans, j + 1);
		}
		cout << ans << " ";
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