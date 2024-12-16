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
		if (prime[i] || i * i <= n) {
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

bool valid(int i, int j, int n, int m)
{
	if(min(i, j) <= 0)
		return false;
	if(i > n || j > m)
		return false;
	return true;
}


bool check(int i, int j, int n, int m)
{
	if(valid(i - 1, j - 2, n, m) || valid(i + 1, j - 2, n, m) || valid(i - 1, j + 2, n, m) || valid(i + 1, j + 2, n, m) || valid(i - 2, j - 1, n, m) || valid(i + 2, j - 1, n, m) || valid(i - 2, j + 1, n, m) || valid(i + 2, j + 1, n, m))
		return false;
	return true;

}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(check(i, j, n, m))
			{
				cout << i << " " << j;
				return;
			}
		}
	}
	cout << "1 1";
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