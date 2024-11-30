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
	srand(time(0));
	int a = rand() % 6 + 1;
	int b = rand() % 6 + 1;
	int c = rand() % 6 + 1;
	int n = a + b + c;
	cout << "1\n" << n << "\n";
	string s = "";
	while(a--)
		s += 'a';
	while(b--)
		s += 'b';
	while(c--)
		s += 'c';
	cout << s << "\n";
	ll m = rand() % (n * n) + 1;
	while(m--)
		next_permutation(s.begin(), s.end());
	cout << s;
	// cout << a << " " << b << " " << c << "\n";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}