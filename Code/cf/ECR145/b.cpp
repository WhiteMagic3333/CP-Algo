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

ll ap_sum(ll n){
	return n * (n + 1) / 2LL;
}

ll find_n(ll cost){
	if(cost % 2){
		return (ap_sum(cost) - 2 * ap_sum((cost - 1) / 2)) * 4LL; 
	}
	return 1LL + 2LL * ap_sum(cost / 2LL) * 4LL;
}
 
void solve()
{
	/*
cost  n
0 	  1   
1     4
2     1 + 8
3     4 + 12
4     
*/
	ll n;
	cin >> n;
	ll ans = 0;
	ll low = 0, high = 1e9;
	while(low <= high){
		ll mid = low + (high - low) / 2;
		ll max_n = find_n(mid);
		if(max_n >= n)
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
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