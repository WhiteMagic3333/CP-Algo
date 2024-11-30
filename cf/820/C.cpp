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
	ll cost = abs(str[str.length() - 1] - str[0]);
	vector<pair<char, int>> ans;
	char mn = min(str[0], str[str.length() - 1]);
	char mx = max(str[0], str[str.length() - 1]);
	int n = str.length();
	for (int i = 1; i < n - 1; i++)
	{
		char ch = str[i];
		if(ch >= mn && ch <= mx){
			ans.push_back({ch, i + 1});
		}
	}
	if(str[0] > str[n - 1])
		sort(ans.begin(), ans.end(), greater<pair<char, int>> ());
	else
		sort(ans.begin(), ans.end());
	ll jumps = 2 + ans.size();
	cout << cost << " " << jumps << "\n";
	cout << "1 ";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].second << " ";
	cout << n;
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