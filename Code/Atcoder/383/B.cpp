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

int d;

int count(int i, int j, int k, int l, vector<vector<char>> &grid, int r, int c) {
	if (grid[i][j] == '#' || grid[k][l] == '#') {
		return 0;
	}

	int ans = 0;

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (grid[x][y] == '.' && ((abs(x - i) + abs(y - j)) <= d || (abs(x - k) + abs(y - l)) <= d))
				ans++;
		}
	}

	return ans;
}
 
void solve()
{
	// Errors
	// empty character cannot be intialized to char
	// multiset.erase(element) is wrong
	// instead use multiset.erase(multiset.find(element))
	int r, c;
	cin >> r >> c >> d;
	vector<vector<char>> grid(r, vector<char> (c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = 2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int i1 = 0; i1 < r; i1++) {
				for (int j1 = 0; j1 < c; j1++) {
					ans = max(ans, count(i, j, i1, j1, grid, r, c));
				}
			}
		}
	}
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}