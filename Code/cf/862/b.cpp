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
	return out;
}
 
void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	char mn = str[0];
	int index = 0;
	for (int i = 1; i < n; i++){
		char ch = str[i];
		if(ch <= mn){
			mn = ch;
			index = i;
		}
	}
	vector<char> ans;
	for (int i = 0; i < n; i++){
		char ch = str[i];
		if(ch > mn && i < index){
			ans.push_back(mn);
			ans.push_back(ch);
			for (int j = i + 1; j < n; j++){
				if(j == index)
					continue;
				ans.push_back(str[j]);
			}
			break;
		}
		else
			ans.push_back(ch);
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