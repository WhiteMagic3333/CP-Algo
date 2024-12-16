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
	return out;
}
 
void solve()
{
	ll n, x;
	cin >> n >> x;
	if(n % x != 0)
		return void(cout << "-1");
	vector<ll> arr(n + 1);
	arr[1] = x;
	arr[x] = n;
	arr[n] = 1;
	for (int i = 2; i < n; i++)
	{
		if(i == x)
			continue;
		arr[i] = i;
	}
	int i = x;
	while(i < n)
	{
		int j = i + 1;
		while(j < n)
		{
			if(j % i == 0 && arr[i] % j == 0)
				break;
			j++;
		}
		if(j == n)
			break;
		swap(arr[i], arr[j]);
		i = j;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i + 1] << " ";
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