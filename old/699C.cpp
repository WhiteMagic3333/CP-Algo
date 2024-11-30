#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<set>
#include<numeric>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define rlp(i,a,b) for (int i = b; i >= b; i--)
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
	vector<int> a(n), b(n), c(m), ans(m);
	cin >> a >> b >> c;
	set<array<int, 2>> present, diff;
	for (int i = 0; i < n; i++) {
		present.insert({b[i], i});
		if (a[i] != b[i])
			diff.insert({b[i], i});
	}
	if (count(b.begin(), b.end(), c[m - 1]) == 0)
		return void(cout << "NO\n");
	for (int i = m - 1; i >= 0; i--)
	{
		auto p = diff.lower_bound({c[i], 0});
		if (p != diff.end() && (*p)[0] == c[i])
		{
			ans[i] = (*p)[1] + 1;
			diff.erase(p);
		}
		else {
			p = present.lower_bound({c[i], 0});
			if (p != present.end() && (*p)[0] == c[i])
			{
				ans[i] = (*p)[1] + 1;
				present.erase(p);
			}
			else
				ans[i] = ans[i + 1];
		}
	}
	if(diff.size())
		return void(cout << "NO\n");
	cout << "YES\n";
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
	}
	return 0;
}