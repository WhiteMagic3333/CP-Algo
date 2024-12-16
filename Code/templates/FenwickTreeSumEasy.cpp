#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<numeric>
using namespace std;
typedef long long ll;

ll sum (vector<ll> &bit, int i)// sum till i
{
	ll ans = 0;
	while (i)
	{
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

void update(vector<ll> &arr, vector<ll> &bit, int i, ll e) // add x to element at index i
{
	ll x = e - arr[i];
	arr[i] = e;
	while (i < bit.size())
	{
		bit[i] += x;
		i += (i & (-i));
	}
}

ll range_sum(vector<ll> &bit, int i, int j)
{
	return sum(bit, j) - sum(bit, i - 1);
}


void solve()
{
	int n, q;
	cin >> n >> q;
	vector<ll> arr(n + 1), bit(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		ll e;
		cin >> e;
		update(arr, bit, i, e);
	}
	while (q--)
	{
		int ch, a, b;
		cin >> ch >> a >> b;
		if (ch == 1)
			update(arr, bit, a, b);
		else
			cout << range_sum(bit, a, b) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}