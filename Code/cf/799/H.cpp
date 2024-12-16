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
	vector<array<int, 2>> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0];
		arr[i][1] = i;
	}
	sort(arr.begin(), arr.end());
	ll ans = 1, i = arr[0][1], j = arr[0][1], cur = 1, ci = arr[0][1], cj = arr[0][1];
	ll a = arr[0][0];
	for (int index = 1; index < n; index++)
	{
		if (arr[index][0] != arr[index - 1][0])
		{
			cur = 1;
			ci = arr[index][1];
			cj = arr[index][1];
		}
		else
		{
			ll gap = arr[index][1] - cj - 1;
			cur = cur - gap;
			if (cur < 0)
			{
				ci = arr[index][1];
				cur = 0;
			}
			cur++;
			cj = arr[index][1];
		}
		if (ans < cur)
		{
			ans = cur;
			i = ci;
			j = cj;
			a = arr[index][0];
		}
	}
	i++;
	j++;
	cout << a << " " << i << " " << j;
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