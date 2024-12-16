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

// 0 Based Indexing used

void intialize(ll n, vector<vector<ll>> &seg)//jagged vector seg
{
	ll rows = log2(n) + ((n & (n - 1)) ? 2 : 1);
	ll cur = n + n % 2;
	seg.resize(rows);
	for (int i = 0; i < rows; i++) {
		seg[i].resize(cur, 1e10);
		cur = cur / 2 + cur % 2;
	}

}

void build(vector<vector<ll>> &seg, int i, int element) // udpate i'th element in array to element
{
	seg[0][i] = element;
	ll other;
	for (int k = 1; k < int(seg.size()); k++)
	{
		if (i % 2)
			other = seg[k - 1][i - 1];
		else
			other = seg[k - 1][i + 1];
		ll first = seg[k - 1][i];
		i = i / 2;
		seg[k][i] = min(first, other);
	}
}

ll query(vector<vector<ll>> &seg, int i, int j)// min in range [i, j]
{
	ll ans = 1e10, k = 0;
	i = i * 2, j = j * 2;
	do {
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
	} while (i < j);
	return ans;
}

void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	vector<vector<ll>> seg;
	intialize(n, seg);//intialize rows and columns
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		build(seg, i, arr[i]);
	}
	while (q--)
	{
		int ch, a, b;
		cin >> ch >> a >> b;
		if (ch == 1)
			build(seg, a - 1, b);
		else
			cout << query(seg, a - 1, b - 1) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}