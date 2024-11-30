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
		std::cout << x ;
	return out;
}

bool bigger(vector<char> &a, vector<char> &b)
{
	int n = a.size(), m = b.size();
	int i = 0, j = 0;
	while(i < n && j < m){
		if(a[i] < b[j])
			return false;
		i++;
		j++;
	}
	if(j != m)
		return false;
	return true;
}

bool fun(vector<char> &a, vector<char> &b, vector<char> &c){
	if(a.size() && b.size() && c.size())
	{
		if(bigger(a, b) && bigger(c, b))
			return true;
		if(bigger(b, a) && bigger(b, c))
			return true;
	}
	return false;
}

void solve()
{
	string str;
	cin >> str;
	int n = str.length();
	vector<char> a, b, c;
	for (int i = 0; i < n; i++)
	{
		a.push_back(str[i]);
		b.clear();
		for (int j = i + 1; j < n; j++)
		{
			b.push_back(str[j]);
			c.clear();
			for (int k = j + 1; k < n; k++)
			{
				c.push_back(str[k]);
			}
			if(fun(a, b, c))
			{
				cout << a << " " << b << " " << c;
				return;
			}
		}
	}
	cout << ":(";
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