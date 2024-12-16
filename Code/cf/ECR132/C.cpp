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
	vector<int> pre(n, 0);
	int open = count(str.begin(), str.end(), '(');
	int close = count(str.begin(), str.end(), ')');
	int open_rem = n / 2 - open;
	int close_rem = n / 2 - close;
	int i = 0, start = 0, end = 2e5 + 1;
	while (i < n)
	{
		if (str[i] == '?')
		{
			if (open_rem) {
				start = max(start, i);
				str[i] = '(';
				open_rem--;
			}
			else if (close_rem) {
				end = min(end, i);
				str[i] = ')';
				close_rem--;
			}
		}
		i++;
	}
	if (open == n / 2 || close == n / 2 )
		return void(cout << "YES");
	swap(str[start], str[end]);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			pre[i]++;
		else
			pre[i]--;
		pre[i] = pre[i] + (i == 0 ? 0 : pre[i - 1]);
		if (pre[i] < 0)
			return void(cout << "YES");
	}
	cout << "NO";
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