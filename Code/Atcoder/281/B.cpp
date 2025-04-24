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

bool digit(char ch)
{
	if(ch <= '9' && ch >= '0')
		return true;
	return false;
}

bool ua(char ch)
{
	if(ch <= 'Z' && ch >= 'A')
		return true;
	return false;
}

void solve()
{
	string str;
	cin >> str;
	
	int n = str.length();

	bool flag = true;
	
	int i = 0;
	if(ua(str[i]))
		i++;
	else
		flag = false;
	ll mid = 0;
	while(i < n && digit(str[i]))
	{
		mid = mid * 10LL + (str[i] - '0') * 1LL;
		i++;
	}
	if(mid < 100000 || mid > 999999 || str[1] == '0')
		flag = false;

	if(i != n - 1 || ua(str[i]) == false)
		flag = false;
	if(flag)
		cout << "Yes";
	else
		cout << "No";

	

	

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}