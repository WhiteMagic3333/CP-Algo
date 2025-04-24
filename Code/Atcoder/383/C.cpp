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
		std::cout << x << ' ';
	std::cout << '\n';
	return out;
}

int d, r, c;

bool valid(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &cool) {
	if (min(i, j) < 0 || i >= r || j >= c || grid[i][j] == '#' || cool[i][j]) {
		return false;
	}
	return true;
}

void add_direction(queue<vector<int>> &q, int i, int j, int _d, vector<vector<char>> &grid, vector<vector<bool>> &cool) {
	vector<vector<int>> dir = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0},
	};
	for (auto &di : dir) {
		int _i = i + di[0];
		int _j = j + di[1];
		if (valid(_i, _j, grid, cool)) {
			q.push({_i, _j, _d});
		}
	}
}


void solve()
{
	cin >> r >> c >> d;
	vector<vector<char>> grid(r, vector<char> (c));
	vector<vector<bool>> cool(r, vector<bool> (c, false));

	queue<vector<int>> q;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'H') {
				q.push({i, j, d});
			}
		}
	}

	while(q.size()) {
		vector<int> cur = q.front();
		q.pop();
		cool[cur[0]][cur[1]] = true;
		if (cur[2]) {
			int _d = cur[2] - 1;
			add_direction(q, cur[0], cur[1], _d, grid, cool);
		}
	}

	int ans = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (cool[i][j]) {
				ans++;
			}
		}
	}

	string a;
	int b;
	b = a;

	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}