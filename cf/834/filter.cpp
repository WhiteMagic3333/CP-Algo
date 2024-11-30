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
		std::cout << x;
	std::cout << '\n';
	return out;
}

void fun(vector<char> &a, string &s)
{
	for (char i : s)
		a.push_back(i);
}

void solve()
{
	int n = 57;
	string li = "<li>", _li = "</li>", a= "<a href=", _a = ">Click Me</a>";
	while (n--)
	{
		string str;
		getline(cin, str);
		vector<char> cur;
		int i = 0, len = str.length();
		while (str[i] != '.')
			i++;
		i += 2;
		fun(cur, li);
		while (i < len)
		{
			cur.push_back(str[i]);
			if (str[i] == ':') {
				cur.push_back(' ');
				i += 3;
				break;
			}
			i++;
		}
		fun(cur, a);
		while (i < len) {
			if (str[i] != ' ')
				cur.push_back(str[i]);
			i++;
		}
		fun(cur, _a);
		fun(cur, _li);
		cout << cur;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}