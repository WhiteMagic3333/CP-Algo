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

void fix(multiset<ll> &left, multiset<ll> &right)
{
	int last = *(left.rbegin());
	int first = *(right.begin());
	if (first < last)
	{
		left.erase(last);
		right.erase(first);
		left.insert(first);
		right.insert(last);
	}
}

void solve()
{
	int k, n;
	cin >> n >> k;
	vector<ll> arr(n), pre(n);
	cin >> arr;
	pre[0] = arr[0];
	for (int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + arr[i];
	multiset<ll> left, right;
	for (int i = 0; i < k - 1; i++)
	{
		if (left.size() == right.size())
			left.insert(arr[i]);
		else
			right.insert(arr[i]);
		if (right.size())
			fix(left, right);
	}
	ll ans = 0;
	// for (auto i : left)
	// 	cout << i << " ";
	// cout << '\n';
	// for (auto i : right)
	// 	cout << i << " ";
	for (int i = k - 1; i < n; i++)
	{
		if (left.size() == right.size())
			left.insert(arr[i]);
		else
			right.insert(arr[i]);
		fix(left, right);
		for (auto i : left)
			cout << i << " ";
		cout << '\n';
		for (auto i : right)
			cout << i << " ";
		cout << "\n\n___________\n";
		ll sum = pre[i] - (i >= k ? pre[i - k] : 0LL);
		ll median = *(left.rbegin());
		ll occurences = left.count(median) + right.count(median);
		sum = sum - median * occurences;
		ll rem = k - occurences;
		sum = sum - rem * median;
		ans += sum;
		// cout << ans << " ";
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}