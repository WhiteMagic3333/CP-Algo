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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	set<int> a, b, c;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a')
			a.insert(i);
		else if (s[i] == 'b')
			b.insert(i);
		else
			c.insert(i);
	}
	int i = 0;
	while (i < n)
	{
		if (s[i] == t[i])
		{
			if (a.find(i) != a.end())
				a.erase(i);
			else if (b.find(i) != b.end())
				b.erase(i);
			else
				c.erase(i);
			i++;
		}
		else
		{
			if (t[i] == 'a' || (t[i] == 'b' && s[i] != 'a') || (t[i] == 'c' && s[i] != 'b'))
				return void(cout << "NO");
			bool found = false;
			if (t[i] == 'b')
			{
				if (b.size())
				{
					int index = *(b.begin());
					int other = (c.size() ? ((*c.begin())) : 1e6);
					if (index < other)
					{
						b.erase(index);
						b.insert(i);
						s[i] = 'b';
						s[index] = 'a';
						a.erase(i);
						a.insert(index);
						found = true;
					}
				}
			}
			else if (t[i] == 'c')
			{
				if (c.size())
				{
					int index = *(c.begin());
					int other = (a.size() ? (*(a.begin())) : 1e6);
					if (index < other)
					{
						c.erase(index);
						c.insert(i);
						s[i] = 'c';
						s[index] = 'b';
						b.erase(i);
						b.insert(index);
						found = true;
					}
				}
			}
			if(found == false)
				return void(cout << "NO");

		}
	}
	cout << "YES";

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