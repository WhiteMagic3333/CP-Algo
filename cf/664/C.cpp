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
	vector<int> a(n), b(m);
	cin >> a >> b;
	int answer = 1e5;
	for (int ans = 512; ans >= 0; ans--)
	{
		bool f;
		for (int i = 0; i < n; i++)
		{
			f = false;
			for (int j = 0; j < m; j++)
			{
				int c = a[i] & b[j];
				if ((c | ans) == ans) {
					f = true;
					break;
				}
			}
			if (f == false)
				break;
		}
		if (f == true) {
			answer = ans;
		}
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}