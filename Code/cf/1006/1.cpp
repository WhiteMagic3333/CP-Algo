#include <unordered_map>
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

bool valid(int *f) {
	int a = -1;
	for (int i = 0; i < 26; i++) {
		int freq = f[i];
		if (freq) {
			if (a == -1) {
				a = freq;
			} else if (freq != a) {
				return false;
			}
		}
	}
	return true;
}

void longestBalancedSubstring(char *s, int n, int &mx) {
	int f[26] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			f[s[j] - 'a']++;
			if (valid(f)) {
				mx = max(mx, j - i + 1);
			}
		}
	}
}
 
void solve()
{
	int n;
	cin >> n;
	char s[n];
    cin >> s;

    int max_length;
    longestBalancedSubstring(s, n, max_length);
    cout << max_length;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}