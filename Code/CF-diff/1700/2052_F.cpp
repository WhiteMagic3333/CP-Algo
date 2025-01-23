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
	int n;
	cin >> n;
	vector<vector<char>> grid(2, vector<char> (n));
	cin >> grid[0] >> grid[1];
	string ans = "Unique";
	for (int i = 0; i < n - 1; i++) {
		if (grid[0][i] == grid[1][i]) {
			if (grid[0][i] == '#') {
				continue;
			}
			if (grid[0][i + 1] == grid[1][i + 1] && grid[0][i + 1] == '.') {
				ans = "Multiple";
				i++;
			}
		} else {
			if (grid[0][i] == '.') {
				if (grid[0][i + 1] == '#') {
					ans = "None";
					break;
				}
				grid[0][i + 1] = '#';
			} else {
				if (grid[1][i + 1] == '#') {
					ans = "None";
					break;
				}
				grid[1][i + 1] = '#';
			}
		}
	}
	if (grid[0][n - 1] != grid[1][n - 1]) {
		ans = "None";
	}
	cout << ans;
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