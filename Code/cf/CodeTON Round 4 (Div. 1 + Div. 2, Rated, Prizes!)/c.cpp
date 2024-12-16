#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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
	ll n, c, d;
	cin >> n >> c >> d;
	set<ll> s;
	vector<ll> arr;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll a;
		cin >> a;
		if(s.find(a) == s.end()){
			s.insert(a);
			arr.push_back(a);
		}
		else{
			ans += c;
		}
	}
	ll could_be = n * c + d;
	sort(arr.begin(), arr.end());
	// cout << arr;
	n = arr.size();
	ll extra = 1e18;
	for (int i = n - 1; i >= 0; i--){
		ll cur = arr[i] - (i + 1);
		cur = cur * d + (n - 1LL - i) * c;
		extra = min(extra, cur);
	}
	ans += extra;
	ans = min(ans, could_be);
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