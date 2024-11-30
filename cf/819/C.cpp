#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
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
	n = n * 2;
	string str;
	cin >> str;
	stack<int> st;
	vector<array<int, 2>> v;
	vector<bool> end(n + 1, false);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			st.push(i);
		else if (st.size())
		{
			int index = st.top();
			st.pop();
			v.push_back({index, i});
			end[i] = true;
		}
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][0] == 0 || end[v[i][0] - 1] == false)
			ans++;
	}
	cout << ans;
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