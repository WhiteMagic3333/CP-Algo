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

void pre_cal(vector<ll> &pre) {
	for (int i = 3; i < 1e5 + 1; i++) {
		for (int j = 2; (j * (j + 1)) / 2 <= i; j++) {
			if (j % 2) {// odd divisor
				if (i % j == 0)//divible by odd number
					pre[i] += 2;
			}
			else if(i % j == (j / 2)){
				pre[i] += 2;
			}
		}
	}

	// 2 consective, 3, 4, 5.....
	// sum of N natural numbers n * (n + 1)/2


	//2 + 3 = 5 
	//5, 7, 9, 11
	//n % 2 == 1
	//n % 4 == 2
	//n % 6 == 3
	//n % 8 == 4
	//odd
	//5
	//n-2, n - 1, n, n + 1, n + 2

	//6 -> 3
	//n/3 - 1, n/3, n/3 + 1
	//1, 2, 3

}

void solve()
{
	ll n, c;
	cin >> n >> c;
	vector<ll> arr(n);
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<ll> pre(1e5 + 1, 2);
	//N * Sqrt(N)
	//10^5 * 500;

	// 1, [0, 1] = 2
	// 2, ([-1, .. 1], 2) = 2


	// 

	// 5
	// 5, (-4, -3, -2, .. 4) = 0 , 5

	// if previous consective elements element are making
	// a sum "e", then we have 2 extra subarrays

	pre_cal(pre);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (pre[arr[i]] > c)
			ans++;
	}
	cout << ans;
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