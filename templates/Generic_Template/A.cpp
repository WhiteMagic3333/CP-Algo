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

void update(vector<int> &arr, vector<int> &rev, int i, int j) {
	int n = arr.size();
	int rev_i = n - i - 1;
	int rev_j = n - j - 1;
	swap(arr[i], arr[j]);
	swap(rev[i], rev[j]);
}
 
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	int q;
	cin >> q;
	vector<int> rev = arr;
	reverse(rev.begin(), rev.end());
	bool is_reversed = false;
	while(q--) {
		int op;
		cin >> op;
		if (op == 1) {
			is_reversed = !is_reversed;
		} else if (op == 2) {
			int i, j;
			cin >> i, j;
			if (is_reversed) {
				update(rev, arr, i, j);
			} else {
				update(arr, rev, i, j);
			}
		} else {
			int i;
			cin >> i;
			if (is_reversed) {
				cout << rev[i];
			} else {
				cout << arr[i];
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