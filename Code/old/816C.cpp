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
	int n, m;
	cin >> n >> m;
	vector<ll> arr(n), pre(n), diff(n);
	cin >> arr;
	ll ans = 1;
	ll sum = 0, diff_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if(i == 0 || arr[i] != arr[i - 1])
			diff[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		diff_sum += diff[i];
		sum += diff_sum;
		pre[i] = (diff_sum + 1) * (i + 1) - sum;
	}
	cout << diff;
	cout << pre; 
	while(m--)
	{
		int i, x;
		cin >> i >> x;
		i--;
		arr[i] = x;
		if(i == 0 || arr[i] != arr[i - 1])
			diff[i] = 1;
		if(i != n - 1 && arr[i + 1] != arr[i])
			diff[i + 1] = 1;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}