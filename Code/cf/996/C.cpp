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

ll row_sum(vector<vector<ll>> &grid, int r) {
	ll sum = 0;
	for (int j = 0; j < grid[r].size(); j++) {
		sum += grid[r][j];
	}
	return sum;
}

ll col_sum(vector<vector<ll>> &grid, int c) {
	ll sum = 0;
	for (int i = 0; i < grid.size(); i++) {
		sum += grid[i][c];
	}
	return sum;
}
 
void solve()
{
	int n, m;
	cin >> n >> m;
	string path;
	cin >> path;
	vector<vector<ll>> grid(n, vector<ll> (m));
	for (auto &row : grid) {
		cin >> row;
	}
	int i = 0, j = 0;
	for (char &ch : path) {
		if (ch == 'D') {
			grid[i][j] = (-1LL) * row_sum(grid, i);
			i++;
		} else {
			grid[i][j] = (-1LL) * col_sum(grid, j); 
			j++;
		}
	}
	if (path.back() == 'D') {
		grid[i][j] = (-1LL) * row_sum(grid, i); 
	} else {
		grid[i][j] = (-1LL) * col_sum(grid, j); 
	}
	for (auto &row : grid) {
		cout << row;
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
	}
	return 0;
}