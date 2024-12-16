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
	for (auto p = 0; p < v.size(); p++)
		cout << v[p] << " ";
	std::cout << '\n';
	return out;
}

bool check(int i, int j, vector<vector<int>> &dp)
{
	if (i != 0 && dp[i - 1][j] == 0)
		return false;
	if (j != 0 && dp[i][j - 1] == 0)
		return false;
	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	vector<vector<int>> dp_even(n + 1, vector<int> (n + 1, 1));
	vector<vector<int>> dp_odd(n + 1, vector<int> (n + 1, 0));
	for (int j = 1; j <= n; j++)
	{
		int turn = (j + 1) / 2;
		if (turn % 2){
			dp_even[0][j] = 0;
			dp_odd[0][j] = 1;
		}
	}
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2)
			odd++;
		else
			even++;
	}
	for (int i = 1; i <= even; i++)
	{
		for (int j = 1; i + j <= n; j++)
		{
			if (check(i - 1, j, dp_even) == false && check(i, j - 1, dp_odd) == false)
				dp_even[i][j] = 0;
			if(check(i - 1, j, dp_odd) || check(i, j - 1, dp_even))
				dp_odd[i][j] = 1;
		}
	}
	if (dp_even[even][odd])
		cout << "Alice";
	else
		cout << "Bob";
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