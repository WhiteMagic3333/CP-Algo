#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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

void debug()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> arr(n);
	cin >> arr;
	cout << n << "_" << m << "_" << k;
	for (int i = 0; i < n; i++)
		cout << "_" << arr[i];
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> arr(n);
	cin >> arr;
	int range_size = n - m + 1;
	set<array<int, 3>> s; // max in extreme elements, start, end;
	for (int i = 0; i + range_size - 1 < n; i++)
	{
		int mx = max(arr[i], arr[i + range_size - 1]);
		s.insert({mx, i + 1, i + range_size});
	}
	k = min(m - 1, k);
	int start = 0, end = n + 1;
	while (1)
	{
		auto p = s.begin();
		int st = (*p)[1];
		int e = (*p)[2];
		if (start > st || end < e)
		{
			s.erase(p);
		}
		else if ((start + k) >= st)
		{
			k = k - (st - start);
			start = st;
			s.erase(p);
		}
		else if ((end - k) <= e)
		{
			k = k - (end - e);
			end = e;
			s.erase(p);
		}
		else
			break;
	}
	int ans = (*s.begin())[0];
	cout << ans;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> arr = sieve(n);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve();
		cout << "\n";
	}
	return 0;
}




update(2, 3, x)
A			1 2  3   4     5
D           1 1  1 + x 1 	  1 - x
Ps          1 2  3 + x 4 + x   5

