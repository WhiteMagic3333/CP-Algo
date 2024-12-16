#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<map>
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
	vector<int> arr(n);
	map<ll, ll> index;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		index[arr[i]] = i;
	}
	vector<int> dp(n + 1, 0);
	for (int i = n - 1; i > 0; i--) {
		if (index[i + 1] > index[i])
			dp[i] = dp[i + 1] + 1;
	}
	for (int i = 1; i <= n / 2; i++){
		ll total = dp[i] + 1;
		if(total >= (n - (i - 1) * 2))
			return void(cout << i - 1);
	}
	cout << n / 2;
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