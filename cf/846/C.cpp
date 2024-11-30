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

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> meal(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		meal[cur]++;
	}
	vector<ll> table(m);
	multiset<ll, greater<ll>> dish_lover;
	cin >> table;
	for (int i = 1; i <= n; i++)
		if(meal[i])
			dish_lover.insert(meal[i]);
	sort(table.begin(), table.end(), greater<ll>());
	ll ans = 0;
	for (int i = 0; i < m && dish_lover.size(); i++){
		ll cur = *(dish_lover.begin());
		dish_lover.erase(dish_lover.begin());
		ll mn = min(cur, table[i]);
		cur -= mn;
		ans += mn;
		if(cur)
			dish_lover.insert(cur);
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