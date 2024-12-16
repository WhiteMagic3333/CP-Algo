#include<bits/stdc++.h>
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

int m[262145];

void solve()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;

	ll ans = (n * (n + 1)) / 2;

	vector<ll> sq;

	for (int i = 0; i * i <= 2 * n + 5; i++)
		sq.push_back(i * i);

	ll mn = min(262144LL, 2 * n + 5);

	memset(m, 0, sizeof(int) * mn);

	m[0] = 1;
	ll cur = 0;
	for (int j = 0; j < n; j++)
	{
		cur = cur ^ arr[j];
		for (int i = 0; i < sq.size(); i++)
		{
			ll rem = sq[i] ^ cur;
			if (rem <= mn)
				ans -= m[rem];
		}
		m[cur]++;
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