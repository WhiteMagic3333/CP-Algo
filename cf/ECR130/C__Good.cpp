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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int i = 0;
	while (i < n)
	{
		if (s[i] == t[i])
			i++;
		else
		{
			if (t[i] == 'a' || (t[i] == 'b' && s[i] != 'a') || (t[i] == 'c' && s[i] != 'b'))
				return void(cout << "NO");
			int j = i + 1;
			bool found = false;
			if (t[i] == 'b')
			{
				while (j < n && s[j] != 'c')
				{
					if (s[j] == 'b')
					{
						found = true;
						break;
					}
					j++;
				}
			}
			else if (t[i] == 'c')
			{
				while (j < n && s[j] != 'a')
				{
					if (s[j] == 'c')
					{
						found = true;
						break;
					}
					j++;
				}
			}
			if (found)
			{
				swap(s[i], s[j]);
				i = j;
			}
			else
				return void(cout << "NO");
		}
	}
	cout << "YES";
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