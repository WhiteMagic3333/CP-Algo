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

bool fun(vector<vector<char>> grid)
{
	int m = grid[0].size();
	int i = 0, j = 0;
	if(grid[i][j] == 'W')
		i++;
	if(grid[i][j] == 'W')
		return false;
	while(j < m)
	{
		grid[i][j] = 'W';
		if(grid[(i + 1) % 2][j] == 'B')
			i = (i + 1) % 2;
		else if(j < m && grid[i][j + 1] == 'B')
			j++;
		else
			break;
	}
	ll cnt = count(grid[0].begin(), grid[0].end(), 'B');
	cnt += count(grid[1].begin(), grid[1].end(), 'B');
	if(cnt == 0)
		return true;
	return false;
}


void solve()
{
	ll m;
	cin >> m;
	vector<vector<char>> grid(2, vector<char> (m));
	cin >> grid[0] >> grid[1];
	if(fun(grid))
		return void(cout << "YES");
	swap(grid[0], grid[1]);
	if(fun(grid))
		return void(cout << "YES");
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