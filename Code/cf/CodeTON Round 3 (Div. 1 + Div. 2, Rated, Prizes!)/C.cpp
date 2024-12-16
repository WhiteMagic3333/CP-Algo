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

void solve()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<int> moves(n, 0), cur(n, 0);
	vector<array<int, 2>> ans;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '0') {
			moves[i]--;
			ans.push_back({i + 1, i + 1});
		}
	}
	int tot = ans.size();
	for (int i = 0; i < n; i++)
	{
		int mvs = moves[i] + tot;
		cur[i] = int(b[i] - '0');
		if (mvs % 2)
			cur[i] = 1 - cur[i];

	}
	int cnt = count(cur.begin(), cur.end(), 1);
	if (cnt > 0 && cnt < n)
		return void(cout << "No\n");
	cout << "Yes\n";
	if (cnt == 0)
		ans.push_back({1, n});
	else
	{
		ans.push_back({1, 1});
		ans.push_back({2, n});
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i[0] << " " << i[1] << "\n";
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
	}
	return 0;
}