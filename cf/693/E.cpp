#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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

void add(map<ll, array<ll, 2>> &m, set<ll> &vis, vector<array<ll, 2>> &arr, int i)
{
	if (vis.find(arr[i][0]) == vis.end())
		m[arr[i][0]] = {arr[i][1], i};
	vis.insert(arr[i][0]);
	m[arr[i][0]] = min(m[arr[i][0]], {arr[i][1], i});
}

bool check(map<ll, array<ll, 2>> &m, set<ll> &vis, ll a, ll b)
{
	auto p = vis.lower_bound(a);
	if(p == vis.begin())
		return false;
	p--;
	int index = *p;
	if(m[index][0] < b)
	{
		cout << m[index][1] << " ";
		return true;
	}
	return false;
}

void solve()
{
	int n;
	cin >> n;
	set<ll> vis;
	map<ll, array<ll, 2>> m;// {dimension, {min_other_dimension, index_of_this_}}
	vector<array<ll, 2>> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		add(m, vis, arr, i);
	}
	ll inf = 1e10;
	array<ll, 2> cur = {inf, inf};
	for (auto &present : m)
	{
		cur = min(cur, present.second);
		present.second = min(cur, present.second);
	}
	for (int i = 1; i <= n; i++)
	{
		if(check(m, vis, arr[i][0], arr[i][1]))
			continue;
		if(check(m, vis, arr[i][1], arr[i][0]))
			continue;
		cout << "-1 ";
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