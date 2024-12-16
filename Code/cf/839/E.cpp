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

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	vector<int> asc = arr;
	sort(asc.begin(), asc.end());
	vector<int> dsc = asc;
	reverse(dsc.begin(), dsc.end());
	vector<int> a, b, com;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != asc[i] && arr[i] != dsc[i])
			com.push_back(i);
		else if (arr[i] != asc[i])
			a.push_back(i);
		else if (arr[i] != dsc[i])
			b.push_back(i);
	}
	int turn = 0;//0 -> a, 1 -> b
	while (1)
	{
		if (turn == 0)
		{
			if (a.size())
				a.pop_back();
			else if (com.size() > 1)
				com.pop_back();
			else if (com.size() == 1)
			{
				if (b.size())
					return void(cout << "First");
				else
					return void(cout << "Tie");
			}
			if (com.size() == 0 && a.size() == 0)
				return void(cout << "First");
		}
		else
		{
			if (b.size())
				b.pop_back();
			else if (com.size() > 1)
				com.pop_back();
			else if (com.size() == 1)
			{
				if (a.size())
					return void(cout << "Second");
				else
					return void(cout << "Tie");
			}
			if (com.size() == 0 && b.size() == 0)
				return void(cout << "Second");
		}
		turn = turn ^ 1;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}