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

void fun(array<int, 2> &arr, char &m)
{
	if (m == 'L')
		arr[1]--;
	else if (m == 'R')
		arr[1]++;
	else if (m == 'U')
		arr[0]--;
	else
		arr[0]++;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	array<int, 2> final, cur, mn, mx;
	final[0] = n;
	final[1] = m;
	mn = mx = cur = final;
	for (int k = 0; k < str.length(); k++)
	{
		fun(cur, str[k]);
		int x = 0, y = 0;
		if (cur[0] < 1)
			x = 1;
		else if (cur[0] > n)
			x = -1;
		else if (cur[1] < 1)
			y = 1;
		else if (cur[1] > m)
			y = -1;
		final[0] += x;
		final[1] += y;
		cur[0] += x;
		cur[1] += y;
		mn[0] = min(mn[0] + x, cur[0]);
		mn[1] = min(mn[1] + y, cur[1]);
		mx[0] = max(mx[0] + x, cur[0]);
		mx[1] = max(mx[1] + y, cur[1]);
		if (mn[0] < 1 || mn[1] < 1 || mx[0] > n || mx[1] > m)
		{
			final[0] -= x;
			final[1] -= y;
			break;
		}
	}
	cout << final[0] << " " << final[1];
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