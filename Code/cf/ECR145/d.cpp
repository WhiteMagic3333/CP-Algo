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
	string str;
	cin >> str;
	int n = str.length();
	if(n == 1)
		return void(cout << "0");
	ll sw = 1e12, del = 1e12 + 1;
	vector<ll> left(n), right(n);
	ll o = 0, z = 0;
	for (int i = 0; i < n; i++){
		if(str[i] == '0')
			left[i] = o * del;
		else{
			if(i == n - 1 || str[i + 1] == '1'){
				o++;
				left[i] = o * del;
			}
			else{
				left[i] = o * del + sw;
				o++;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--){
		if(str[i] == '1'){
			right[i] = z * del;
		}
		else{
			if(i == 0 || str[i - 1] == '0'){
				z++;
				right[i] = z * del;
			}
			else{
				right[i] = z * del;
				z++;
			}
		}
	}
	ll ans = min(right[0], left[n - 1]);
	for (int i = 1; i < n; i++){
		ll cur = left[i - 1] + right[i];
		ans = min(ans, cur);
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