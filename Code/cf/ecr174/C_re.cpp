#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<math.h>
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

long long ap_sum(ll n) {
	return ((n * (n + 1)) / 2LL) % mod;
}

void pre(ll n, vector<vector<ll>> &seg)
{
	ll rows = log2(n) + ((n & (n - 1)) ? 2 : 1);
	ll cur = n + n % 2;
	seg.resize(rows);
	for (int i = 0; i < rows; i++) {
		seg[i].resize(cur, 0);
		cur = cur / 2 + cur % 2;
	}
 
}
 
void update(vector<vector<ll>> &seg, int i, int j, ll element)
{
	ll other, k = 0;
	i = i * 2, j = j * 2;
	do {
		i = i / 2;
		j = j / 2;
		if (i % 2) {
			seg[k][i] += ap_sum(element);
			i++;
		}
		if (j % 2 == 0) {
			seg[k][j] += ap_sum(element);
			j--;
		}
		k++;
	} while (i < j);
}
 
ll query(vector<vector<ll>> &seg, int i)
{
	ll ans = 0;
	for (int j = 0; j < seg.size(); j++, i = i / 2)
		ans = ans + seg[j][i];
	return ans;
}
 
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	vector<vector<ll>> seg;
	pre(n, seg);
	int sz = 0;
	for (int i = 0; i < n; i++) {
		update(seg, 0, sz, 1);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			sz++;
		} else if (arr[i] == 2) {
			seg.update(1, sz, 1);
		} else if (sz > 0) {
			ans += seg.query()
			ans += bit.prefixSum(sz - 1);
		}
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