#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<math.h>
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

int K = 32;

//spare table for a
vector<vector<ll>> st(2e5 + 2, vector<ll> (K + 1));

ll fun(ll L, ll R)
{
	ll j = log2(R - L + 1);
	ll maximum = max(st[L][j], st[R - (1 << j) + 1][j]);
	return maximum;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	cin >> a;
	vector<array<ll, 2>> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i][0];
		b[i][1] = i;
		st[i][0] = b[i][0];
	}
	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1LL << j) <= n; i++)
			st[i][j] = max(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
	
	int m;
	cin >> m;
	multiset<ll> s;
	for (int i = 0; i < m; i++)
	{
		ll razor;
		cin >> razor;
		s.insert(razor);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i][0])
			return void(cout << "No");
	}

	sort(b.begin(), b.end(), [&] (array<ll, 2> x, array<ll, 2> y) {
		if (x[0] > y[0])
			return true;
		if (x[0] == y[0])
			return x[1] < y[1];
		return false;
	});

	for (int i = 0; i < n; i++){
		if(b[i][0] == a[b[i][1]])
			continue;
		int j = i + 1;
		while(j < n && b[i][0] == b[j][0] && fun(b[i][1], b[j][1]) == b[i][0])
			j++;
		if(s.find(b[i][0]) == s.end() || s.size() == 0)
			return void(cout << "No");
		s.erase(s.find(b[i][0]));
		i = j - 1;
	}
	cout << "Yes";
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