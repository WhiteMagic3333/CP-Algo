#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <array>
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

ll calc(vector<array<ll, 2>> &arr, ll pos)
{
	ll ans = 0LL;
	for (int i = 0; i < arr.size(); i++)
	{
		ans += abs(pos - arr[i][0]) + arr[i][1];
	}
	return ans;
}

void solve()
{
	ll n;
	cin >> n;
	vector<int> a(n), t(n);
	cin >> a >> t;
	int mn = 1e8, mx = 0, largest = 0;
	for (int i = 0; i < n; i++)
		largest = max(largest, t[i]);
	for (int i = 0; i < n; i++)
	{
		if (largest == t[i]) {
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < mn)
		{
			int now = largest - t[i];
			now = now + a[i];
			mn = min(mn, now);
		}
		else if (a[i] > mn)
		{
			int now = largest - t[i];
			if(now >= a[i])
				now = 0;
			else
				now = a[i] - now;
			mx = max(mx, now);
		}
	}
	int sum = (mn + mx) / 2;
	cout << sum;
	if ((mn + mx) % 2)
		cout << ".5";
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