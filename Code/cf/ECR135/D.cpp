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

void solve()
{
	string str;
	cin >> str;
	int n = str.length();
	vector<vector<ll>> dp(n, vector<ll> (n));
	vector<vector<char>> last(n, vector<char> (n));
	for(int j = 0; j < n; j++){
		last[j][j] = str[j];
		dp[j][j] = 2;
	}
	//dp[i][j]->
	//1 alice wins
	//2 draw
	//3 bob wins
	for (int len = 2; len <= n; len++)
	{
		for (int i = 0; i + len - 1 < n; i++)
		{
		 	int j = i + len - 1;
		 	if(len % 2 == 0)// alice's turn
		 	{
		 		if(dp[i][j - 1] == 1 || dp[i + 1][j] == 1 )
		 		{
		 			dp[i][j] = 1;
		 			last[i][j] = str[j];
		 		}
		 		else if(dp[i][j - 1] == 2 && last[i][j - 1] > str[j] || (dp[i + 1][j] == 2 && last[i + 1][j] > str[i]))
		 		{
		 			dp[i][j] = 1;
		 			last[i][j] = str[i];
		 		}
		 		else if(dp[i][j - 1] == 2 && last[i][j - 1] == str[j])
		 		{
		 			dp[i][j] = 2;
		 			last[i][j] = str[j];
		 		}
		 		else
		 		{
		 			dp[i][j] = 2;
		 			last[i][j] = str[i];
		 		}
		 	}
		 	else// bob's turn
		 	{
		 		if(dp[i][j - 1] == 2 && dp[i + 1][j] == 2)
		 		{
		 			dp[i][j] = 2;
		 			last[i][j] = min(str[i], str[j]);
		 		}
		 		else if(dp[i][j - 1] == 2)
		 		{
		 			dp[i][j] = 2;
		 			last[i][j] = str[j];
		 		}
		 		else if(dp[i + 1][j] == 2)
		 		{
		 			dp[i][j] = 2;
		 			last[i][j] = str[i];
		 		}
		 		else
		 		{
		 			dp[i][j] = 1;
		 			last[i][j] = min(str[i], str[j]);
		 		}
		 	}
		}
	}
	if(dp[0][n - 1] == 1)
		cout << "Alice";
	else
		cout << "Draw";
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