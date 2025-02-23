#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<stack>
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

bool opening(char ch) {
	if (ch == '(' || ch == '[' || ch == '<') {
		return true;
	}
	return false;
}

bool closing(char ch) {
	return !opening(ch);
}

char op(char ch) {
	if (ch == ')') {
		return '(';
	} else if (ch == ']') {
		return '[';
	} else {
		return '<';
	}
}

 
void solve()
{
	string str;
	cin >> str;
	stack<char> s;
	for (char ch : str) {
		if (opening(ch)) {
			s.push(ch);
		} else {
			if (s.size() > 0 && s.top() == op(ch)) {
				s.pop();
			} else {
				return void(cout << "No");
			}
		}
	}
	if (s.size() == 0) {
		cout << "Yes";
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