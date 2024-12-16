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
 
ll sod(ll a){
	ll d = 0;
	while(a)
	{
		d += a % 10;
		a = a / 10;
	}
	return d;
}
 
void solve()
{
	ll n;
	cin >> n;
	ll x = n, y = 0;
	ll a = sod(x), b = sod(y);
	ll target = a / 2, cur = 1;
	while(abs(a - b) > 1)
	{
		cur *= 10;
		if(cur <= x * 10){
			ll extra = x % cur;
			ll digit = extra / (cur / 10);
			digit = min(digit, target);
			extra = digit * (cur / 10);
			y += extra;
			x -= extra;
			target -= digit;
		}
		a = sod(x), b = sod(y);
	}
	cout << x << " " << y;
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