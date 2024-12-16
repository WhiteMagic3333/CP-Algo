#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
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

long long mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

long long fun(long long n, long long k) {
	long long a = n / 2, b = n / 2 + n % 2;
	ll pwr = k - 1;
	long long cur = binpow(a, pwr, mod);
	cur = cur * binpow(b, pwr, mod);
	cur = cur % mod;
	return cur;
}


int maxScore(vector<int> &t, vector<int> &s)// rename to t and s
{
	int q = t.size();
	long long ans = 1;
	while (q--)
	{
		long long cur_ans = fun(t[q], s[q]);
		ans = (ans * cur_ans) % mod;
	}
	return ans;
}


void solve()
{
	int n;
	cin >> n;
	vector<int> total(n), sizes(n);
	cin >> total >> sizes;
	cout << maxScore(total, sizes);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}