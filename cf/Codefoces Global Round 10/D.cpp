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
	string str;
	cin >> str;
	int c = count(str.begin(), str.end(), 'L');
	if(c == n || c == 0){
		c = n;
		return void(cout << c / 3 + (c % 3 ? 1 : 0));
	}
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if(str[i] != str[(i - 1 + n) % n]){
			index = i;
			break;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = (index + i + 2) % n;
		int prev = (cur - 1 + n) % n;
		int prev_prev = (prev - 1 + n) % n;
		if(str[cur] == str[prev] && str[cur] == str[prev_prev]){
			str[cur] = '$';
			ans++;
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve();
		cout << "\n";
	}
	return 0;
}
