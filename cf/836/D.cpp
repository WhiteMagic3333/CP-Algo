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
vector<ll> sq;


void solve()
{
	ll n;
	cin >> n;
	ll cur = n;
	ll sum = (n * (n + 1)) / 2;
	// cout << sum << "\n";
	while(1)
	{
		ll sq = cur * cur;
		ll r = sq - sum;
		ll new_sum = (r / n + 1) * n + sum;
		// cout << sq << " " << new_sum << "\n";
		ll rem = new_sum - sq;
		// cout << rem << "\n";
		ll mx = (cur - n + 1) * (n - 1);
		if(rem + n - 1 >= cur && rem <= mx)
		{
			ll mn = 1;
			mx = n;
			ll d = r / n + 1;
			ll sub = cur - n + 1;
			// cout << mn + d - sub << " " << mx + d;
			for(ll j = 1; j <= n; j++)
			{
				ll cur = j + d;
				if(rem)
				{
					cur -= min(rem, sub);
					rem -= min(rem, sub);
				}
				cout << cur << " ";
			}
			break;
		}
		cur++;
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