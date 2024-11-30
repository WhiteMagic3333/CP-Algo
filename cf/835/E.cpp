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
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0, cur_ans = 0, z = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if(arr[i] == 0)
			z++;
		else
			ans += z;
	}
	vector<ll> ones(n);
	ones[0] = arr[0];
	for (int i = 1; i < n; i++)
		ones[i] = ones[i - 1] + arr[i];
	z = 0;
	cur_ans = ans;
	for (ll i = n - 1; i >= 0; i--)
	{
		ll ones_before = ones[i] - arr[i];
		if(arr[i] == 0)
		{
			cur_ans = max(cur_ans, ans - ones_before + z);
			z++;
		}
		else
		{
			cur_ans = max(cur_ans, ans + ones_before - z);
		}
	}
	cout << cur_ans;
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