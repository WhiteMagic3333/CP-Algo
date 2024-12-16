#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<numeric>
using namespace std;
typedef long long ll;

// 1 based indexing


/*
we have to find the largest power of 2 that divides x


-x = 2's complement of x
2's complement = x' + 1
x' (or x complement) is simply x with all its bits inverted

let x = a1b (in binary form where 1 is the last 1 in x and b is 0)
-x = x' + 1
RHS
(a1b)' + 1
(a1(00..00))' + 1
a'0(11..11) + 1
a'1(00..00)
a'1b

So
-x = a'1b
x = a1b

hence
x & (-x) = a1b & (a'1b) = largest power of 2 that divides x
because
a   1  b
a'  1  b
__________
0's 1  0's



*/

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