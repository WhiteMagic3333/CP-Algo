#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;

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

void fun(string &s, vector<int> &z) {
	int n = s.size();

	int x = 0, y = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			x = i; y = i + z[i]; z[i]++;
		}
	}
}

void solve()
{
	string pattern;
	cin >> pattern;

	int n = pattern.length();
	vector<int> z(n, 0);
	fun(pattern, z);
	for (int i = n - 1; i >= 0; i--)
	{
		if(i + z[i] == n)
			cout << z[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}