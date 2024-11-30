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

// bool diverse(string &str, int &index, int final, vector<vector<ll>> &table)
// {
// 	int distinct = 0;
// 	for (int i = 0; i < 10; i++) {
// 		freq[i] = table[final][i] - table[index][i];
// 		if (freq[i])
// 			distinct++;
// 	}
// 	freq[str[index] - '0']++;
// 	int mx = *max_element(freq.begin(), freq.end());
// 	if (mx > distinct)
// 		return false;
// 	return true;
// }

void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	ll ans = 0;
	vector<vector<ll>> freq(n, vector<ll> (10, 0));
	freq[0][(str[0] - '0')]++;
	for (int i = 1; i < n; i++)
	{
		freq[i] = freq[i - 1];
		freq[i][str[i] - '0']++;
	}
	for (int i = 0; i < n; i++)
	{
		vector<ll> fre(10, 0);
		ll last = min(i + 99, n - 1);
		fre = freq[last];
		for (int j = 0; j < 10; j++)
			fre[j] -= freq[i][j];
		fre[int(str[i] - '0')]++;
		ll distinct = 10 - count(fre.begin(), fre.end(), 0);
		for (int final = min(i + 99, n - 1); final >= i; final--)
		{
			ll mx = *max_element(fre.begin(), fre.end());
			if (mx <= distinct)
				ans++;
			fre[str[final] - '0']--;
			if (fre[str[final] - '0'] == 0)
				distinct--;
		}
	}
	cout << ans;
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