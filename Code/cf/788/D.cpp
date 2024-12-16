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

ll calc(ll total)
{
	ll q = total / 3;
	ll a = q, b = q, c = q;
	ll rem = total % 3;
	if(rem)
		a++;
	if(rem > 1)
		b++;
	return a * b + b * c + c * a;
}

void solve()
{
	ll n;
	cin >> n;
	if(n % 2)
		n++;
	n = n / 2;
	ll ans = 1e5;
	ll low = 2;
	ll high = 1e5;
	while(low <= high)
	{
		ll mid = low + (high - low) / 2LL;
		ll triangles = calc(mid);
		if(triangles >= n)
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