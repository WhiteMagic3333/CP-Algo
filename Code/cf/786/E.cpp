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

void ac(int a, int c, ll &ans)
{
	int moves = min(a, c);
	int rem = a + c - 2 * moves;
	moves = moves + (rem / 2 + rem % 2);
	ans = min(ans, moves * 1LL);
}

void ab(int a, int b, ll &ans)
{
	int moves = 0, rem = 0;
	if (a > b)
		swap(a, b);
	if (a * 2 <= b)
	{
		moves = a;
		rem = b - 2 * a;
		moves = moves + rem / 2 + rem % 2;
	}
	else
	{
		moves = (a + b) / 3 + min(1, (a + b) % 3);
	}
	ans = min(ans, moves * 1LL);
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 1e18;
	ll smallest = 0;
	ll second_smallest = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < arr[smallest])
			smallest = i;
	}
	if (smallest == 1)
		second_smallest = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < arr[second_smallest] && i != smallest)
			second_smallest = i;
	}
	ans = (arr[smallest] / 2 + arr[smallest] % 2) + (arr[second_smallest] / 2 + arr[second_smallest] % 2);
	for (int i = 1; i < n - 1; i++)
	{
		//abc -> i - 1, i, i + 1
		//for ac
		ac(arr[i - 1], arr[i + 1], ans);
		//for ab
		ab(arr[i - 1], arr[i], ans);
	}
	ab(arr[n - 2], arr[n - 1], ans);
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}