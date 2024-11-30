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
	for (T& x : v) {
		in >> x;
		x--;
	}
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
	cin >> arr;
	vector<int> p(n, 0);
	int index = 1;
	ll cycles = 0;
	for (int i = 0; i < n; i++)
	{
		if(p[i])
			continue;
		ll cur = i;
		while(p[cur] == 0)
		{
			p[cur] = index;
			cur = arr[cur];
		}
		index++;
		cycles++;
	}
	for (int i = 0; i < n - 1; i++){
		if(p[i] == p[i + 1])
			return void(cout << n - cycles - 1);
	}
	cout << n - cycles + 1;
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