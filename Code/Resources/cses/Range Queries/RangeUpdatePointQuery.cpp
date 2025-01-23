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
			seg[k][i] += element;
			i++;
		}
		if (j % 2 == 0) {
			seg[k][j] += element;
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
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	vector<vector<ll>> seg;
	pre(n, seg);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		seg[0][i] = arr[i];
	}
	while (q--)
	{
		int ch;
		cin >> ch;
		if (ch == 2) {
			int k;
			cin >> k;
			cout << query(seg, k - 1) << "\n";
		}
		else {
			int i, j, e;
			cin >> i >> j >> e;
			update(seg, i - 1, j - 1, e);
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