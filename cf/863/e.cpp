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

vector<ll> fours(18, 0);

void pre() {

	fours[1] = 1;
	for (int digit = 2; digit <= 18; digit++) {
		fours[digit] = fours[digit - 1] * 9;
	}
	// cout << fours;
}

ll ahead(ll num) {
	ll cur = 4;
	ll ten = 10;
	ll digit = 1;
	ll add = 0, till_last_digit;
	while (cur <= num) {
		ll times = (num / ten) * fours[digit]; //complete
		ll extra = (num % ten);
		if (extra >= cur) {
			//partial
			ll total = min(fours[digit], extra - cur + 1);
			ll sub = ahead(extra % 10);
			add += total - sub;
		}
		add += times;
		//end
		digit++;
		ten *= 10;
		cur *= 10;
	}
	return add;
}

void solve()
{
	ll k;
	cin >> k;
	ll add = ahead(k);
	cout << k + add;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}