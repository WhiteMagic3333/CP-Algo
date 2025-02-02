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
	vector<vector<char>> a(n, vector<char> (n));
	vector<vector<char>> b(m, vector<char> (m));
	for (auto &row : a) {
		for (auto &col : row) {
			cin >> col;
		}
	}
	for (auto &row : b) {
		for (auto &col : row) {
			cin >> col;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool valid = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					int di = i + k, dj = j + l;
					if (di >= n || dj >= n || a[di][dj] != b[k][l]) {
						valid = false;
					}
				}
			}
			if (valid) {
				return void (cout << i + 1 << " " << j + 1);
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