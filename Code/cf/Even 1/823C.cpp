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

void solve()
{
	string str;
	cin >> str;
	int n = str.length();
	vector<int> next_min(n, n);
	for (int i = n - 2; i >= 0; i--)
	{
		next_min[i] = next_min[i + 1];
		if (next_min[i] == n || str[i + 1] <= str[next_min[i]])
			next_min[i] = i + 1;
	}
	multiset<char> m;
	int i = 0;
	if (next_min[0] != n && str[0] > str[next_min[0]])
	{
		for (i = 0; i < next_min[0]; i++)
			m.insert(min('9', char(str[i] + 1)));
	}
	while (i < n)
	{
		while (m.size() && (*m.begin()) < str[i])
		{
			cout << *(m.begin());
			m.erase(m.begin());
		}
		if (m.size() == 0 || str[i] <= *(m.begin()))
		{
			cout << str[i];
			int j = next_min[i];
			i++;
			while (i < n && i < j) {
				m.insert(min('9', char(str[i] + 1)));
				i++;
			}
		}
	}
	while (m.size())
	{
		cout << *(m.begin());
		m.erase(m.begin());
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