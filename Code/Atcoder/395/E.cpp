#include <ratio>
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

bool check(string &pal, int &len) {
	int i = 0, j = pal.length() - 1;
	while(i < j) {
		if (pal[i] != pal[j]) {
			return false;
		}
		i++;
		j--;
	}
	len = min(len, (int)pal.length());
	return true;
}


bool bfs(vector<vector<pair<int, char>>> &adj, vector<bool> &vis, string &pal, int &start, int &dest, int &len) {
	queue<
}
 
void solve()
{
	int n;
	cin >> n;
	vector<vector<pair<int, char>>> adj(n + 1);
	vector<vector<char>> alpha(n + 1, vector<char> (n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch;
			cin >> ch;
			if (ch != '-') {
				adj[i].push_back({j, ch});
			}
			alpha[i][j] = ch;
		}
	}
	vector<bool> vis(n + 1, false);
	string pal = "";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "0 ";
			} else {
				int len = 1e9;
				if (bfs(adj, vis, pal, i, j, len)) {
					cout << len;
				} else {
					cout << "-1";
				}
				cout << " "; 
			}
		}
		cout << '\n';
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}