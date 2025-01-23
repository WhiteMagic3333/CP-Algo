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

void fun(string &s, vector<int> &z) {
	int n = s.size();

	int x = 0, y = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			x = i; y = i + z[i]; z[i]++;
		}
	}
}

void solve()
{
	//Z algorithm
	string str, pattern;
	cin >> str >> pattern;
	string s = pattern + '#' + str;
	int n = s.length();
	vector<int> z(n, 0);
	fun(s, z);
	int len = pattern.length();
	int ans = count(z.begin(), z.end(), len);
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}