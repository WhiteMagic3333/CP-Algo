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

vector<string> areAlmostEquivalent(vector<string> s, vector<string> t)
{
	int n = s.size();
	vector<string> ans;
	for (int i = 0; i < n; i++)
	{
		vector<int> sf(26, 0), tf(26, 0);
		bool f = true;
		if (s[i].length() == t[i].length())
		{
			for (int j = 0; j < s[i].length(); j++)
			{
				sf[s[i][j] - 'a']++;
				tf[t[i][j] - 'a']++; 
			}
			for (int j = 0; j < 26; j++)
			{
				if (abs(sf[j] - tf[j]) > 3)
					f = false;
			}
		}
		else
			f = false;
		if (f)
			ans.push_back("YES");
		else
			ans.push_back("NO");
	}
	return ans;
}

void solve()
{
	vector<string> s = {"aabaab", "aaaaabb"};
	vector<string> t = {"bbabbc", "abb"};

	vector<string> ans = areAlmostEquivalent(s, t);
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}