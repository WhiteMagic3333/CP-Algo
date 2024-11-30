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

bool process(ll k, multiset<int> s)
{
	for (int i = 1; i <= k; i++)
	{
		ll element = k - i + 1;
		if(s.size() == 0 || (*s.begin()) > element)
			return false;
		auto p = s.upper_bound(element);
		p--;
		s.erase(p);
		if(s.size())
		{
			auto q = s.begin();
			s.erase(s.begin());
		}
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;
	multiset<int> s;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		s.insert(a);
	}
	ll ans = 0;
	ll low = 0, high = 100;
	while(low <= high)
	{
		ll mid = (low + high) / 2;
		if(process(mid, s))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
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