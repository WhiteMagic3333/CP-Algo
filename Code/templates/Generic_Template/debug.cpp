//Debug
// Deb is short for debug

//template to print primitive data types
// and vector, array, set, stack, queue

#ifndef ONLINE_JUDGE
#include "magic.h"
#define debug_primitive(num) cerr << num << '\n';
#define debug(num) cerr << #num << " " << _print(num) << '\n';
#else
#include<bits/stdc++.h>
#define debug_primitive(num)
#define debug(num)
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
	int a;
	cin >> a;
	debug(a);
}
 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("error.out", "w",stderr);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

 
	solve();
	return 0;
}