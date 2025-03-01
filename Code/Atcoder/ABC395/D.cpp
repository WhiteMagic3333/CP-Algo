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
	vector<int> p(n + 1);//pigeons in which next_index
	vector<int> nest(n + 1);// nest name
	vector<int> nest_index(n + 1);
	for (int i = 1; i <= n; i++) {
		nest_index[i] = p[i] = nest[i] = i;
	}
	while(q--) {
		int ch, a, b;
		cin >> ch;
		if (ch == 3) {
			cin >> a;
			cout << nest[p[a]] << "\n";
		} else if (ch == 1) {
			cin >> a >> b;
			p[a] = nest_index[b];
		} else {
			cin >> a >> b;
			swap(nest[nest_index[a]], nest[nest_index[b]]);
			swap(nest_index[a], nest_index[b]);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}