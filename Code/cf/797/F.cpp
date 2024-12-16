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

ll lcm(ll a, ll b)
{
	ll g = __gcd(a, b);
	ll l = (a * b) / g;
	return l;
}

bool valid(vector<int> &loc, string &a, string &b)
{
	for (int i = 0; i < loc.size(); i++)
	{
		if (a[loc[i]] != b[loc[i]])
			return false;
	}
	return true;
}

ll moves(vector<int> &loc, vector<int> &arr, string str)
{
	string cur = str, prev = str;
	int n = str.size();
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cur[j] = prev[arr[j] - 1];
		prev = cur;
		if(valid(loc, cur, str))
			return i;
	}
	return n;
}

void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> arr(n);
	cin >> arr;
	vector<bool> vis(n, false);
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			vector<int> loc;
			loc.push_back(i);
			int cur = arr[i] - 1;
			while (cur != i)
			{
				vis[cur] = true;
				loc.push_back(cur);
				cur = arr[cur] - 1;
			}
			// cout << loc;
			ll m = moves(loc, arr, str);
			ans = lcm(ans, m);
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