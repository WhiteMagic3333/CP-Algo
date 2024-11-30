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
	vector<int> arr(n);
	cin >> arr;
	int cnt = 0, index = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			cnt++;
			index = i;
		}
	}
	if (cnt != 1)
		return void(cout << "NO");
	for (int i = 1; i < n; i++)
	{
		int prev = arr[(n + index + i - 1) % n];
		int cur = arr[(i + index) % n];
		if (cur - prev > 1)
			return void(cout << "NO");
	}
	cout << "YES";
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