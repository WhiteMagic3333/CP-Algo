#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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

void solve()
{
	int n;
	cin >> n;
	vector<long long> arr(n);
	cin >> arr;
	set<long long> ans;
	stack<long long> s;
	s.push(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (s.top() > arr[i]) {
			ans.insert(s.top() - arr[i]);
		}
		else {
			while (s.size() && s.top() <= arr[i]) {
				ans.insert(arr[i] - s.top());
				s.pop();
			}
			if(s.size())
				ans.insert(s.top() - arr[i]);
		}
		s.push(arr[i]);
	}
	cout << ans.size();
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