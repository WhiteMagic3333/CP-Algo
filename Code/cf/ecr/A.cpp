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
	cin >> arr;
	vector<bool> vis(n, false);
	sort(arr.begin(), arr.end(), greater<ll>());

	if(arr[0] == arr[n - 1])
		return void(cout << "NO\n");
	cout << "YES\n";
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		if(sum == arr[i])
			continue;
		vis[i] = true;
		sum += arr[i];
		cout  << arr[i] << " ";
	}
	for (int i = 0; i < n; i++)
	{
		if(vis[i] == false)
			cout << arr[i] << " ";
	}
	cout << "\n";
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
	}
	return 0;
}