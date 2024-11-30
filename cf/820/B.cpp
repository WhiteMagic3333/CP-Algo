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
	string str;
	cin >> n;
	cin >> str;
	vector<char> ans;
	int j = n - 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if(str[i] != '0')
		{
			char ch = char('a' - 1 + int(str[i] - '0'));
			ans.push_back(ch);
			j--;
		}
		else
		{
			i--;
			char ch = 'a' - 1 + int(str[i] - '0') + 10 * int(str[i - 1] - '0');
			ans.push_back(ch);
			i--;
		}
	}
	for(int j = ans.size() - 1; j >= 0; j--)
		cout << ans[j];
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