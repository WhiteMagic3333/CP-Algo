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

vector<vector<ll>> ans(1e6 + 1, vector<ll> (4, 0));

void pre() {
	ans[1] = {1, 0, 0, 0};
	for (ll i = 2, turn = 2, cur = 2; i <= 1e6; i++) {
		ans[i] = ans[i - 1];

		if (cur == 0) {
			turn++;
			cur = turn;
		}

		if (turn % 4 == 2 || turn % 4 == 3){
			if(i % 2)
				ans[i][2]++;
			else
				ans[i][3]++;
		}
		else{
			if(i % 2)
				ans[i][0]++;
			else
				ans[i][1]++;
		}
		cur--;
	}
}

void solve()
{
	ll n;
	cin >> n;
	cout << ans[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}