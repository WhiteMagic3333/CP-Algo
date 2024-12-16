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
	cin >> n;
	vector<ll> arr(n);
	vector<ll> pre(n), post(n);
	cin >> arr;
	ll ans = 1, cur = 1;
	pre[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			cur++;
			ans = max(ans, cur);
		}`
		else
			cur = 1;
		pre[i] = cur;
	}
	post[n - 1] = 1;
	cur = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if(arr[i] < arr[i + 1])
			cur++;
		else
			cur = 1;
		post[i] = cur;
	}
	for (int i = 1; i < n - 1; i++)
	{
		if(arr[i - 1] < arr[i + 1])
			ans = max(ans, pre[i - 1] + post[i + 1]);
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}



	["A","B","C","E"]
	["S","F","E","S"]
	["A","D","E","E"]