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
	int n, q;
	cin >> n >> q;
	vector<ll> arr(n), sum(n, 0);
	cin >> arr;
	sum[0] = arr[0];
	for (int i = 1; i < n; i++){
		sum[i] = sum[i - 1] + arr[i];
		arr[i] = max(arr[i], arr[i - 1]);
	}
	while(q--)
	{
		ll k;
		cin >> k;
		ll index = lower_bound(arr.begin(), arr.end(), k + 1) - arr.begin();
		if(index == 0)
			cout << "0 ";
		else
			cout << sum[index - 1] << " ";
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