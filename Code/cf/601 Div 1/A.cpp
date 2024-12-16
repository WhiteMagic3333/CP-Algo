#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
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
		std::cout << x;
	std::cout << '\n';
	return out;
}

bool valid(vector<vector<char>> &final, int i, int j)
{
	int r = final.size();
	int c = final[0].size();
	if (min(i, j) < 0 || i >= r || j >= c || final[i][j] != '.')
		return false;
	return true;
}

void solve()
{
	int r, c, k;
	cin >> r >> c >> k;

	vector<vector<char>> grid(r, vector<char> (c, '.'));
	vector<vector<char>> final(r, vector<char> (c, '.'));
	int rice = 0, used = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'R')
				rice++;
		}
	}

	vector<char> chick;
	for (char i = 'A'; i <= 'Z'; i++)
		chick.push_back(i);
	for (char i = 'a'; i <= 'z'; i++)
		chick.push_back(i);
	for (char i = '0'; i <= '9'; i++)
		chick.push_back(i);

	int req = rice / k, cur = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = i % 2 ? c - 1 : 0; (i % 2 && j >= 0) || (i % 2 == 0 && j < c); i % 2 ? j-- : j++)
		{
			if (req == 0) {
				cur = min(cur + 1, k - 1);
				req = (rice - used) / (k - cur);
			}
			if (grid[i][j] == 'R')
			{
				req--;
				used++;
			}
			final[i][j] = chick[cur];
		}
	}
	for (int i = 0; i < r; i++)
		cout << final[i];
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