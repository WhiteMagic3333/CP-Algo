#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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
 
bool check(ll pre_x, ll pre_y, ll &a, ll &b, ll &c, ll &d)
{
	ll x = (c / pre_x) * pre_x;
	if(x && (a * b) % x == 0)
		pre_y = (a * b) / x;
	ll y = (d / pre_y) * pre_y;
	if(x > a && y > b)
	{
		cout << x << " " << y;
		return true;
	}
	return false;
}
 
void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<ll> f1, f2;
	ll mx = max(a, b) + 1;
	for (ll i = 1; i * i < mx; i++)
	{
		if (a % i == 0) {
			f1.push_back(i);
			f1.push_back(a / i);
		}
		else if (b % i == 0)
		{
			f2.push_back(i);
			f2.push_back(b / i);
		}
	}
	vector<ll> factors;
	for (ll i : f1)
		factors.push_back(i);
	for (ll i : f2)
		factors.push_back(i);
	for (ll i : f1)
	{
		for (ll j : f2)
		{
			factors.push_back(i * j);
		}
	}
	bool flag = true;
	for (ll i : factors)
	{
		ll j = (a * b) / i;
		if(check(i, j, a, b, c, d) || check(j, i, a, b, c, d))
		{
			flag = false;
			break;
		}
	}
	if(flag)
		cout << "-1 -1";
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