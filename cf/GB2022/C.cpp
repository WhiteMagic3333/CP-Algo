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

bool check(ll x, vector<ll> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(__gcd(arr[i] + x, arr[j] + x) % 3 == 0)
				return true;
		}
	}
	return false;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	set<int> s;
	int o = 0, e = 0;
	for (int i : arr){
		s.insert(i);
	}
	if (s.size() != n || (o > 1 && e > 1))
		return void(cout << "NO");

	if(o > e)
	{
		if(check(2, arr) && check(4, arr) && check(6, arr))
			return void(cout << "NO");
	}
	else
	{
		if(check(1, arr) && check(3, arr) && check(5, arr))
			return void(cout << "NO");
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