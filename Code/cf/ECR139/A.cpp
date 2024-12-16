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

vector<ll> pre(1e6, 0);

int check(int n)
{
	vector<int> f(10, 0);
	while(n)
	{
		int cur = n % 10;
		f[cur]++;
		n = n / 10;
	}
	int sum = accumulate(f.begin(), f.end(), 0);
	sum = sum - f[0];
	if(sum == 1)
		return 1;
	else
		return 0;
}

void pref(){

	for (int i = 1; i < 1e6; i++)
	{
		pre[i] = pre[i - 1] + check(i);
	}
}

void solve()
{
	ll n;
	cin >> n;
	cout << pre[n];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	pref();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}