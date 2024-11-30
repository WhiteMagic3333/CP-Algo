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

void find_match(vector<ll> &k, ll a, ll b, ll c) {
	int index = upper_bound(k.begin(), k.end(), b) - k.begin();
	int n = k.size();
	if(index == n)
		index--;
	ll c1 = k[index];
	ll d1 = abs(b - c1) * abs(b - c1);
	if(index != 0)
		index--;
	ll c2 = k[index];
	ll d2 = abs(b - c2) * abs(b - c2);
	ll cur, diff;
	if(d1 <= d2){
		cur = c1;
		diff = d1;
	}
	else{
		cur = c2;
		diff = d2;
	}
	if(diff >= (4LL * a * c))
		return void(cout << "NO\n");
	cout <<  "YES\n";
	cout << cur << "\n";

}

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> k(n), a(m), b(m), c(m);
	cin >> k;
	sort(k.begin(), k.end());
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		find_match(k, a, b, c);
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
	}
	return 0;
}