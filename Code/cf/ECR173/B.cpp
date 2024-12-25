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

ll _sod(ll times, ll d) {
	return times * d;
}
 
void solve()
{
	int n, d;
	cin >> n >> d;

	// here times is n!
	vector<int> ans;
	ans.push_back(1);
	if (n > 2 || d % 3 == 0) {
		ans.push_back(3);
	}
	if (d % 5 == 0) {
		ans.push_back(5);
	}
	//check for 7
	if (n > 2 || d == 7) {
		ans.push_back(7);
	}
	if ((d == 9) || (n > 5) || (d % 3 == 0 && n > 2)) {
		ans.push_back(9);
	}
	cout << ans;
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