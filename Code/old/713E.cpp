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
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	vector<int> inside, outside;
	int sum = 0, left = 0;
	for (int i = 1; i <= n; i++)
	{
		int rem = r - l - left;
		int rem_sum = n * (n + 1) / 2 - (n - rem) * (n - rem + 1) / 2;
		if ((sum + i + rem_sum) >= s)
		{
			sum += i;
			inside.push_back(i);
			left++;
		}
	}
	if (sum != s)
		return void(cout << "-1");
	for (int i = 1; i <= n; i++)
		if (find(inside.begin(), inside.end(), i) == inside.end())
			outside.push_back(i);


	int i = 0, j = 0;
	for (int k = 1; k <= n; k++)
	{
		if (k >= l && k <= r)
			cout << inside[i++] << " ";
		else
			cout << outside[j++] << " ";
	}
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