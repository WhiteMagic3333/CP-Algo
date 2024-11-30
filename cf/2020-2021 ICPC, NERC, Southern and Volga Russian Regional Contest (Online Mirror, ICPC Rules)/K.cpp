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

void fun(char ch, array<int, 2> &arr)
{
	switch (ch)
	{
	case 'L':
		arr[0]--;
		break;
	case 'R':
		arr[0]++;
		break;
	case 'U':
		arr[1]++;
		break;
	case 'D':
		arr[1]--;
		break;
	}
}

void redo(char ch, array<int, 2> &arr)
{
	switch (ch)
	{
	case 'L':
		arr[0]++;
		break;
	case 'R':
		arr[0]--;
		break;
	case 'U':
		arr[1]--;
		break;
	case 'D':
		arr[1]++;
		break;
	}
}


void solve()
{
	string str;
	cin >> str;
	array<int, 2> arr = {0, 0};
	set<array<int, 2>> s;
	for (int i = 0; i < str.length(); i++)
	{
		fun(str[i], arr);
		s.insert(arr);
	}
	s.erase({0, 0});
	arr = {0, 0};
	for (auto p : s)
	{
		for (int i = 0; i < str.length(); i++)
		{
			fun(str[i], arr);
			if (arr[0] == p[0] && arr[1] == p[1])
				redo(str[i], arr);
		}
		if (arr[0] == 0 && arr[1] == 0)
			return void(cout << p[0] << " " << p[1]);
		arr = {0, 0};
	}
	return void(cout << "0 0");
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