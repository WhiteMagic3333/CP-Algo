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
	return out;
}
 
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	set<int> a, b;
	vector<int> p(n, -1), q(n, -1);
	for (int i = 1; i <= n; i++)
	{
		a.insert(i);
		b.insert(i);
	}
	for (int i = 0; i < n; i++)
	{
		if(a.find(arr[i]) != a.end())
		{
			p[i] = arr[i];
			a.erase(arr[i]);
		}
		else if(b.find(arr[i]) != b.end())
		{
			q[i] = arr[i];
			b.erase(arr[i]);
		}
		else
			return void(cout << "NO\n");
	}
	for (int i = 0; i < n; i++)
	{
		if(p[i] == -1)
		{
			auto ptr = a.upper_bound(arr[i]);
			if(ptr == a.begin())
				return void(cout << "NO\n");
			ptr--;
			p[i] = *ptr;
			a.erase(*ptr);
		}
		else if(q[i] == -1)
		{
			auto ptr = b.upper_bound(arr[i]);
			if(ptr == b.begin())
				return void(cout << "NO\n");
			ptr--;
			q[i] = *ptr;
			b.erase(*ptr);
		}
	}
	cout << "YES\n";
	cout << p << '\n';
	cout << q << '\n';
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