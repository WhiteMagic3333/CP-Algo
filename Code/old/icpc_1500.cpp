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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> arr(n, vector<int> (m));
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while(k--)
	{
		int a;
		cin >> a;
		a--;
		int i = 0, j = a;
		while(i < n)
		{
			int val = arr[i][j];
			arr[i][j] = 2;
			if(val == 1)
				j = j + 1;
			else if(val == 3)
				j = j - 1;
			else
				i = i + 1;
		}
		cout << j + 1 << " ";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}