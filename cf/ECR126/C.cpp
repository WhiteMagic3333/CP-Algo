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

bool valid(ll days, vector<ll> &arr, ll last)
{
	ll even = days / 2;
	ll odd = days - even;
	for (int i = 0; i < arr.size(); i++)
	{
		ll diff = last - arr[i];
		ll evens = min(diff / 2, even);
		ll odds = min(diff - evens * 2LL, odd);
		diff = diff - odds - evens * 2;
		if(diff)
			return false;
		odd = odd - odds;
		even = even - evens;
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	sort(arr.begin(), arr.end());
	ll ans = 1e18;
	ll low = 0, high = 1e18;
	while(low <= high)
	{
		ll mid = low + (high - low) / 2LL;
		if(valid(mid, arr, arr.back()) || valid(mid, arr, arr.back() + 1))
		{
			ans = min(ans, mid);
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