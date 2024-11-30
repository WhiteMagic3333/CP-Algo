#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
vector<int> largest_prime(3e5 + 1, 0);

void sieve(ll n)
{
	prime.resize(n + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (prime[i]) {
			largest_prime[i] = i;
			for (ll j = i * i; j <= n; j += i) {
				largest_prime[j] = i;
				prime[j] = false;
			}
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

const int mx = 3e5 + 1;

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	int s, t;
	cin >> s >> t;
	if (s == t)
		return void(cout << "1\n" << s);
	s--, t--;
	vector<vector<int>> adj(n), fact(mx);
	vector<bool> vis(n, false), vis_fact(mx, false);
	vector<int> prev(n, -1), prev_fact(mx);
	for (int i = 0; i < n; i++)
	{
		int cur = arr[i];
		while (cur > 1)
		{
			int f = largest_prime[cur];
			fact[f].push_back(i);
			adj[i].push_back(f);
			while (cur % f == 0)
				cur = cur / f;
		}
	}
	queue<array<int, 2>> q;
	q.push({t, 0});//{index, distance}
	vis[t] = true;
	while (q.size())
	{
		int i = q.front()[0], dis = q.front()[1];
		q.pop();
		if (dis % 2 == 0)
		{	// array element
			for (int j = 0; j < adj[i].size(); j++)
			{
				if (vis_fact[adj[i][j]] == false)
				{
					q.push({adj[i][j], dis + 1});
					vis_fact[adj[i][j]] = true;
					prev_fact[adj[i][j]] = i;
				}
			}
		}
		else
		{	// prime factor
			for (int j = 0; j < fact[i].size(); j++)
			{
				if (vis[fact[i][j]] == false)
				{
					q.push({fact[i][j], dis + 1});
					vis[fact[i][j]] = true;
					prev[fact[i][j]] = i;
				}
			}
		}
	}
	if (prev[s] == -1)
		return void(cout << "-1");
	int cur = s, parity = 0;
	vector<int> ans;
	while (1)
	{
		if (parity == 0)
		{
			ans.push_back(cur + 1);
			if(cur == t)
				break;
			cur = prev[cur];
		}
		else
			cur = prev_fact[cur];
		parity = parity ^ 1;
	}
	cout << ans.size() << "\n" << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(mx);
	solve();
	return 0;
}