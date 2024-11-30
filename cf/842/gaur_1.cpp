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

ll sum (vector<ll> &bit, int i)// sum till i
{
	ll ans = 0;
	while (i)
	{
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

void update(vector<ll> &bit, int i, ll x) // add x to element at index i
{
	while (i < bit.size())
	{
		bit[i] += x;
		i += (i & (-i));
	}
}

ll range_sum(vector<ll> &bit, int i, int j)
{
	return sum(bit, j) - sum(bit, i - 1);
}

void solve()
{
	int n;
	cin >> n;
	vector<long long> arr(n + 1), bit(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	map<ll, ll> last_index;

	for (int i = 1; i <= n; i++)
		last_index[arr[i]] = i;

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		ll last = last_index[arr[i]];
		if (last == i) {
			update(bit, i, -1LL);
		}
		else {
			ll between = last - i - 1;// or the number of swaps
			ll moved = range_sum(bit, i, last);// already swapped/counted
			ans += between - moved;
			update(bit, last, 1LL);
		}
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