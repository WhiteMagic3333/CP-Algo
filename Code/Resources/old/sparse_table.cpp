#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<numeric>
using namespace std;
#define ll long long
// sparse table are used in range queries
// min/max/gcd can be found using sparse tables for a static range
// preprocessing time -> O(N.Log(N))
// Per query time -> O(1)
// SC -> O(N.Log(N))
// TC -> O(N.Log(N) + Q)
// read this again
// you haven't understood it well :(

vector<ll> bin_log(2e5 + 1, 0LL);

ll query(vector<vector<ll>> &table, ll L, ll R)
{
	int len = R - L + 1;
	ll i = bin_log[len];
	return min(table[i][L], table[i][R - (1LL << i) + 1]);
}

void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (ll i = 2; i <= 2e5; i++)
		bin_log[i] = bin_log[i/2] + 1;
	//creating sparse table
	//max
	vector<vector<ll>> table(33, vector<ll> (n, 0LL));
	table[0] = arr;
	for (ll i = 1; i < 32; i++)
	{
		for (ll j = 0; (j + (1LL << (i)) - 1) < n; j++) {
			table[i][j] = min(table[i - 1][j], table[i - 1][j + (1LL << (i - 1))]);
		}
	}
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		cout << query(table, l - 1, r - 1) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}