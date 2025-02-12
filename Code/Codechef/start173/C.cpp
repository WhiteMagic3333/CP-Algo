#include <queue>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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

bool middle(int l, int h, int m) {
	if ((l + h) % 2 == 0) {
		return m == ((l + h) / 2);
	}
	return (m == ((l + h) / 2)) || (m == ((l + h + 1) / 2));
}

bool check_gap(int l, int h) {
	return (l / 2) != (h / 2);
}

void add(set<array<ll, 3>> &s, int low, int high) {
	int e = high - low - 1;
	s.insert({(e + 1) / 2, low, high});
}
 
void solve()
{
	int n;
	cin >> n;
	vector<int> seat(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		seat[p] = i + 1;
	}
	int second;
	if (seat[1] == n) {
		second = 1;
	} else if (seat[1] == 1) {
		second = n;
	} else {
		return void (cout << "No");
	}
	if (n > 1) {
		if (seat[2] != second) {
			return void (cout << "No");
		}
		//farthest, start, end
		set<array<ll, 3>> range;
		int elements = n - 2;
		set<int> vis;
		vis.insert(1);
		vis.insert(n);
		add(range, 1, n);
		for (int i = 3; i <= n; i++) {
			auto low_it = vis.lower_bound(seat[i]);
			auto high_it = vis.lower_bound(seat[i] + 1);
			low_it--;
			int low = *low_it, high = *high_it;
			int cur_dis = min(seat[i] - low, high - seat[i]);
			array<ll, 3> top = *(range.rbegin());
			if (!middle(low, high, seat[i]) || cur_dis != top[0]) {
				return void(cout << "No");
			}
			range.erase({cur_dis, low, high});
			vis.insert(seat[i]);
			add(range, low, seat[i]);
			add(range, seat[i], high);
		}
	}
	cout << "Yes";
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