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
	vector<ll> odd, even;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		if (a % 2)
			odd.push_back(a);
		else
			even.push_back(a);
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	int turn = 1;//1 alice , 0 bob
	ll alice = 0, bob = 0;
	while (odd.size() && even.size())
	{
		ll e_cur = even.back();
		ll o_cur = odd.back();
		if (turn)
		{
			if(o_cur > e_cur)
				odd.pop_back();
			else
			{
				alice += e_cur;
				even.pop_back();
			}

		}
		else
		{
			if(e_cur > o_cur)
				even.pop_back();
			else
			{
				bob += o_cur;
				odd.pop_back();
			}
		}
		turn = turn ^ 1;
	}
	while (odd.size())
	{
		if (turn == 0)
			bob += odd.back();
		odd.pop_back();
		turn = turn ^ 1;
	}
	while (even.size())
	{
		if (turn)
			alice += even.back();
		even.pop_back();
		turn = turn ^ 1;
	}
	if(alice > bob)
		cout << "Alice";
	else if(bob > alice)
		cout << "Bob";
	else
		cout << "Tie";
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