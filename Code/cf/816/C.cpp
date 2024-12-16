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
	vector<ll> arr(n);
	cin >> arr;
	ll prev = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || arr[i] != arr[i - 1]) {
			prev += i;
		}
		prev += 1;
		ans += prev;
	}
	while (m--)
	{
		ll index, new_element;
		cin >> index >> new_element;
		index--;
		ll left = 0, right = 0;
		if (index != 0)
		{
			ll value = (index * (n - index));
			if (arr[index - 1] != new_element && arr[index - 1] == arr[index])
				left += value;
			else if (arr[index - 1] == new_element && arr[index - 1] != arr[index])
				left -= value;
		}
		if (index != n - 1)
		{
			ll new_index = index + 1;
			ll value = (new_index * (n - new_index));
			if (arr[index + 1] != new_element && arr[index + 1] == arr[index])
				right += value;
			else if (arr[index + 1] == new_element && arr[index + 1] != arr[index])
				right -= value;
		}
		ans += left + right;
		cout << ans << "\n";
		arr[index] = new_element;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}