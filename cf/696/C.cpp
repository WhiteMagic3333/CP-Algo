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

bool check(vector<ll> &arr, multiset<array<ll, 2>> m, int index, int print)
{
	ll sum = arr[index] + arr[arr.size() - 1];
	while(m.size())
	{
		auto last = m.end();
		last--;
		ll l_value = (*last)[0];
		auto first = m.lower_bound({sum - l_value, 0LL});
		if(first == m.end() || first == last){
			break;
		}
		ll f_value = (*first)[0];
		if(l_value + f_value != sum)
			break;
		if(print)
			cout << f_value << " " << l_value << "\n";
		m.erase(last);
		m.erase(first);
		sum = l_value;
	}
	if(m.size())
		return false;
	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(2 * n);
	multiset<array<ll, 2>> backup;
	cin >> arr;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < 2 * n; i++)
		backup.insert({arr[i], i});
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (check(arr, backup, i, 0))
		{
			cout << "YES\n";
			cout << arr[i] + arr[2 * n - 1] << "\n";
			check(arr, backup, i, 1);
			return;
		}
	}
	cout << "NO\n";
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