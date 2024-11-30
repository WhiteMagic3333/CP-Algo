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
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<string> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int len = t.length();
	t = " " + t;
	vector<array<int, 3>> dp(len + 1, {101, -1, -1});//min_len, prev_dp, selected_text
	dp[0] = {0, -1, -1};
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int s = arr[j].length();
			if(s > i)
				continue;
			bool f = true;
			for (int k = s - 1, sub = 0; k >= 0; k--, sub++)
			{
				if(arr[j][k] != t[i - sub])
					f = false;
			}
			if(f == true)
			{
				for (int k = 1; k <= s; k++)
				{
					if(dp[i - k][0] < (dp[i][0] - 1))
					{
						dp[i][0] = dp[i - k][0] + 1;
						dp[i][1] = i - k;
						dp[i][2] = j; 
					}
				}
			}
		}
	}
	if(dp[len][0] > 100)
		return void(cout << "-1\n");
	vector<array<int, 2>> ans;
	int i = len;
	while(dp[i][1] != -1)
	{
		int index = i - arr[dp[i][2]].size() + 1;
		ans.push_back({dp[i][2], index});
		i = dp[i][1];
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i][0] << " " << ans[i][1] << "\n";
	// for(int i = 1; i <= len; i++)
	// 	cout << dp[i][0] << " ";
	// cout << "\n";
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
	}
	return 0;
}