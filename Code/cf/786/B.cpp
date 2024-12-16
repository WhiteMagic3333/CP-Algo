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

vector<vector<int>> arr(26, vector<int> (26, 0));

void pre()
{
	int cnt = 0;
	for(char i = 'a'; i <= 'z'; i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			if(i == j)
				continue;
			cnt++;
			arr[i - 'a'][j - 'a'] = cnt;
		}
	}
}

void solve()
{
	char a, b;
	cin >> a >> b;
	cout << arr[a - 'a'][b - 'a'];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	pre();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}