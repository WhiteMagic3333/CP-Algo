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
	vector<ll> arr(n);
	cin >> arr;
	sort(arr.begin(), arr.end());
	ll i = 0, j = n - 1;
	ll ans = arr[j] - arr[i] + max(arr[i + 1] - arr[i], arr[j] - arr[j - 1]);
	while ((j - i + 1) > 3)
	{
		ll c1 = arr[j] - arr[i + 1] + max(arr[j] - arr[j - 1], arr[i + 2] - arr[i + 1]);
		ll c2 = arr[j - 1] - arr[i] + max(arr[j - 1] - arr[j - 2], arr[i + 1] - arr[i]);
		if(c1 >= ans)
		{
			ans = c1;
			i++;
		}
		else if(c2 >= ans)
		{
			ans = c2;
			j--;
		}
		else
			break;
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