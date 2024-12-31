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

// void fun(string &s, vector<int> &fs) {
// 	for (auto ch : s) {
// 		fs[ch - 'a']++;
// 	}
// }

bool fun(string &s, string&t) {
	//s is smaller, t is larger
	int count = 0;
	for (int i = 0, j = 0; j < s.length(); i++, j++) {
		if (i >= s.length()) {
			count++;
		} else if (s[i] != t[j]) {
			i--;
			count++;
		}
	}
	if (count > 1) {
		return false;
	}
	return true;
}
 
void solve()
{
	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	int n = s.length();
	// int del = 0;
	// vector<int> fs(26, 0), ft(26, 0);
	// fun(s, fs);
	// fun(t, ft);
	// for (int i = 0; i < 26; i++) {
	// 	//extra chars
	// 	del += max(0, fs[i] - ft[i]);
	// }

	// if diff is one


	// if adding one 

	if (s.length() == t.length()) {
		int diff = 0;
		for (int i = 0; i < n; i++) {
			if (t[i] != s[i]) {
				diff++;
				if (diff > 1) {
					return void(cout << "No");
				}
			}
		}
		cout << "Yes";
	} else if (n + 1 == t.length()) {
		if (fun(s, t)) {
			cout << "Yes";
		} else {
			cout << "No";
		}
	} else if (n - 1 == t.length()) {
		if (fun(t, s)) {
			cout << "Yes";
		} else {
			cout << "No";
		}
	} else {
		cout << "No";
	}

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}