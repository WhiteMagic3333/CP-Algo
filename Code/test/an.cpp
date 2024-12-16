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

int minSugar(int n, int x, vector<int> &arr) {
	if(n < x)
		return -1;
	if(x == 0)
		return 0;


	ll ans, cur;
	cur = ans = accumulate(arr.begin(), arr.begin() + x, 0LL);
	for (int i = 0; i < x; i++) {
		cur -= arr[x - i - 1];
		cur += arr[n - 1 - i];
		ans = min(ans, cur);
	}

	return ans;
}


void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	cin >> arr;
	minSugar(n, x, arr);
	// cout << minSugar(n, x, arr);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}