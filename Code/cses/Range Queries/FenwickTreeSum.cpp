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
we have to find the largest power of 2 that divzides x


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

vector<ll> bit(2e5 + 1, 0);

ll sum (int i)// sum till i
{
	ll ans = 0;
	while (i)
	{
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

void update(int i, ll x) // add x to element at index i
{
	while (i <= 2e5)
	{
		bit[i] += x;
		i += (i & (-i));
	}
}


void solve()
{
	int n, q;
	cin >> n >> q;
	vector<ll> arr(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	while (q--)
	{
		int ch, a, b;
		cin >> ch >> a >> b;
		if (ch == 1)
		{
			ll x = b - arr[a];
			arr[a] = b;
			update(a, x);
		}
		else
		{
			cout << sum(b) - sum(a - 1) << "\n";
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