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
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	vector<array<int, 2>> ans;
	for (int i = 0; i < n / 2; i++)
	{
		if(str[i] == ')')
		{
			int j = i + 1;
			while(j < n && str[j] == ')')
				j++;
			ans.push_back({i + 1, j + 1});
			swap(str[i], str[j]);
		}
	}
	int i = 1, j = n / 2;
	k--;
	while(k--)
	{
		ans.push_back({i + 1, j + 1});
		swap(str[i], str[j]);
		i += 2;
		j++;
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i][0] << " " << ans[i][1] << "\n";
	}
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