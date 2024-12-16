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
		std::cout << x ;
	std::cout << '\n';
	return out;
}
 
void solve()
{
	int n, d;
	cin >> n >> d;
	char dig = d + '0';
	string str;
	cin >> str;
	bool used = false;
	vector<char> ans;
	for (int i = 0; i < n; i++){
		int digit = (str[i] - '0');
		if(digit < d){
			used = true;
			ans.push_back(dig);
			for (int j = i; j < n; j++)
				ans.push_back(str[j]);
			break;
		}
		else
			ans.push_back(str[i]);
	}
	if(used == false)
		ans.push_back(dig);
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