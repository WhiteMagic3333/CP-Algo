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

void solve()
{
	int n, k = 0;
	cin >> n;
	set<int> present;
	vector<int> arr(n), ans(n, -1), gifter(n + 1, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		present.insert(i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		if (present.find(arr[i]) != present.end())
		{
			present.erase(arr[i]);
			ans[i] = arr[i];
			gifter[ans[i]] = i;
			k++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == -1)
		{
			auto p = present.begin();
			ans[i] = *p;
			present.erase(*p);
			if (ans[i] == (i + 1))
			{
				swap(ans[i], ans[gifter[arr[i]]]);
			}
		}
	}
	cout << k << "\n";
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
	}
	return 0;
}