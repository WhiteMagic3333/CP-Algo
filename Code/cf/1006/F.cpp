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
	int n = 1, rows = 32;
	vector<vector<int>> arr(rows);
	arr[0].push_back(n);
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				arr[i].push_back(arr[i - 1][j]);
			} else if (i == j) {
				arr[i].push_back(arr[i - 1][j - 1]);
			} else {
				arr[i].push_back(arr[i - 1][j - 1] ^ arr[i - 1][j]);
			}
		}
	}
	for (auto row : arr) {
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
		cout << "\n";
	}
	return 0;
}