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

ll sum (vector<ll> &bit, ll i)// sum till i
{
	ll ans = 0;
	while (i)
	{
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}
 
void update(vector<ll> &arr, vector<ll> &bit, ll i, ll e) // add x to element at index i
{
	ll x = e - arr[i];
	arr[i] = e;
	while (i < bit.size())
	{
		bit[i] += x;
		i += (i & (-i));
	}
}
 
ll range_sum(vector<ll> &bit, ll i, ll j)
{
	return sum(bit, j) - sum(bit, i - 1);
}

void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> row(n + 1, 0), col(n + 1, 0);
	vector<ll> in_row(n + 1, 0), in_col(n + 1, 0);
	vector<ll> bit_row(n + 1, 0), bit_col(n + 1, 0);
	while(q--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			ll x, y;
			cin >> x >> y;
			row[x]++;
			col[y]++;
			if(row[x] == 1)
				update(in_row, bit_row, x, 1);
			if(col[y] == 1)
				update(in_col, bit_col, y, 1);
		}
		else if(t == 2)
		{
			ll x, y;
			cin >> x >> y;
			row[x]--;
			col[y]--;
			if(row[x] == 0)
				update(in_row, bit_row, x, 0);
			if(col[y] == 0)
				update(in_col, bit_col, y, 0);
		}
		else
		{
			ll x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if(range_sum(bit_row, x1, x2) == (x2 - x1 + 1) || range_sum(bit_col, y1, y2) == (y2 - y1 + 1))
				cout << "Yes\n";
			else
				cout << "No\n";
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