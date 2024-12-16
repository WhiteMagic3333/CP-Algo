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

void pre(ll n, vector<vector<ll>> &seg)
{
	ll rows = log2(n);
	if (pow(2, rows) != n)
		rows++;
	ll last = n;
	seg.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		ll s = last / 2 + last % 2;
		seg[i].resize(s, 1e10);
		last = s;
	}
}

void build(vector<vector<ll>> &seg, vector<ll> &arr, int i, int element)
{
	arr[i] = element;
	int other;
	if (i % 2)
		other = arr[i - 1];
	else
		other = (i != int(arr.size()) ? arr[i + 1] : 1e10);
	int j = i / 2;
	seg[0][j] = min(arr[i], 1LL * other);
	for (int k = 1; k < int(seg.size()); k++)
	{
		if (j % 2)
			other = seg[k - 1][j - 1];
		else
			other = seg[k - 1][j + 1];
		ll first = seg[k - 1][j];
		j = j / 2;
		seg[k][j] = min(first, 1LL * other);
	}
}

ll query(vector<vector<ll>> &seg, vector<ll> &arr, int i, int j)
{
	ll ans = 1e10;
	if (i % 2) {
		ans = min(ans, arr[i]);
		i++;
	}
	if (j % 2 == 0) {
		ans = min(ans, arr[j]);
		j--;
	}
	int k = 0;
	while (i < j)
	{
		i = i / 2;
		j = j / 2;
		if (i % 2) {
			ans = min(ans, seg[k][i]);
			i++;
		}

		if (j % 2 == 0) {
			ans = min(ans, seg[k][j]);
			j--;
		}

		k++;
	}
	return ans;
}

void solve()
{
	ll n, q, e;
	cin >> n >> q;
	vector<ll> arr(n);
	vector<vector<ll>> seg;
	pre(n, seg);
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		build(seg, arr, i, e);
	}
	while (q--)
	{
		int ch, a, b;
		cin >> ch >> a >> b;
		if (ch == 1)
			build(seg, arr, a - 1, b);
		else
			cout << query(seg, arr, a - 1, b - 1) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}