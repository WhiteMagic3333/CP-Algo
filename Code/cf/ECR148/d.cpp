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

ll after(ll k) {
	ll p = (k % 2) ? 1 : -1;
	return p * ((k + 1) / 2);
}

ll cal(vector<ll> &arr, ll n, ll k) {
	ll ans = 1e18;
	if(k <= n) {
		for (int i = 0; i < k; i++) {
			ans = min(ans, arr[i] + k - i);
		}
	} else {
		ll unknown = after(k - (n - 1));
		if(unknown < 0) {

		} else {
			ll mn = 1e18;
			for (int i = 0; i < n; i++){
				mn = min(arr[i] + (i != (n - 1) ? k - i : 0) , mn);
			}
			ans = mn + unknown;
		}
	}
	return ans;
}
 
void solve()
{
	int n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	cin >> arr;
	sort(arr.begin(), arr.end());
	while(q--) {
		int k;
		cin >> k;
		cout << cal(arr, n, k) << " ";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}