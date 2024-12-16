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
	string s, t;
	cin >> s >> t;
	ll n = s.length();
	vector<vector<int>> closest(n + 1, vector<int> (26, -1));
	int index;
	for (int i = n - 1; i >= 0; i--)
	{
		closest[i] = closest[i + 1];
		index = int(s[i] - 'a');
		closest[i][index] = i;
	}
	ll ans = 1;
	int j = 0;
	for (int i = 0; i < t.length(); i++)
	{
		int index = int(t[i] - 'a');
		if(closest[0][index] == -1)
			return void(cout << "-1");
		if(closest[j][index] == -1){
			j = 0;
			ans++;
		}
		j = closest[j][index] + 1;
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
		cout << "\n";
	}
	return 0;
}