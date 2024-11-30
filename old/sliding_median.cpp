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

ll l_sum = 0, r_sum = 0;

void move_left(multiset<ll> &left, multiset<ll> &right)
{
	auto first = right.begin();
	left.insert(*first);
	r_sum -= *first;
	l_sum += *first;
	right.erase(first);
}

void move_right(multiset<ll> &left, multiset<ll> &right)
{
	auto last = (left.end());
	last--;
	right.insert(*last);
	l_sum -= *last;
	r_sum += *last;
	left.erase(last);

}
void swap_middle(multiset<ll> &left, multiset<ll> &right)
{
	auto last = (left.end());
	last--;
	auto first = (right.begin());
	left.insert(*first);
	right.insert(*last);
	l_sum = l_sum - *last + *first;
	r_sum = r_sum + *last - *first;
	left.erase(last);
	right.erase(first);
}

void fix(multiset<ll> &left, multiset<ll> &right)
{
	while (left.size() - right.size() > 1)
		move_right(left, right);
	while (right.size() > left.size())
		move_left(left, right);
	if (left.size() && right.size())
	{
		while ( (*(left.rbegin())) > (*(right.begin())) )
			swap_middle(left, right);
	}
}

void solve()
{
	ll k, n;
	cin >> n >> k;
	vector<ll> arr(n), pre(n);
	cin >> arr;
	multiset<ll> left, right;
	for (int i = 0; i < k; i++)
	{
		left.insert(arr[i]);
		l_sum += arr[i];
		fix(left, right);
	}
	ll ans = 0;
	ll median = *left.rbegin();
	ans = abs(l_sum - (ll(left.size()) * median)) + abs(r_sum - (ll(right.size()) * median));
	cout << ans << " ";
	for (int i = k; i < n; i++)
	{
		if (left.find(arr[i - k]) != left.end()) {
			auto p = left.find(arr[i - k]);
			left.erase(p);
			l_sum -= arr[i - k];
		}
		else {
			auto p = right.find(arr[i - k]);
			right.erase(p);
			r_sum -= arr[i - k];
		}

		left.insert(arr[i]);
		l_sum += arr[i];
		fix(left, right);
		median = *left.rbegin();
		ans = abs(l_sum - (ll(left.size()) * median)) + abs(r_sum - (ll(right.size()) * median));
		cout << ans << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}