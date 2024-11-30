#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<map>
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

int dfs(map<char, char> &op, char cur, char req)
{
	if(cur == req)
		return 0;
	if(op[cur] < 'a' || op[cur] > 'z')
		return -1;
	int len = dfs(op, op[cur], req);
	if(len == -1)
		return -1;
	return 1 + len;
}

void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	map<char, char> m;
	map<char, char> opposite;
	map<char, bool> found;
	vector<char> vis(256, false);
	for (int i = 0; i < n; i++)
	{
		if (found[str[i]] == false) {
			for (char j = 'a'; j <= 'z'; j++)
			{
				if (j != str[i] && vis[j] == false && (dfs(opposite, str[i], j) == 25 || dfs(opposite, str[i], j) == -1)) {
					// cout << dfs(opposite, str[i], j) << "\n";
					m[str[i]] = j;
					vis[j] = true;
					opposite[j] = str[i];
					break;
				}
			}
			found[str[i]] = true;
		}
		cout << m[str[i]];
	}
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