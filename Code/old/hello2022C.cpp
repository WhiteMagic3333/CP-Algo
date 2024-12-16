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
	int n;
	cin >> n;
	vector<array<ll, 3>> seg(n);
	for (int i = 0; i < n; i++)
		cin >> seg[i][0] >> seg[i][1] >> seg[i][2];
	set<array<ll, 3>> x, y, z;//{start, cost, end}, {end, cost, start}, {start, end, cost}
	bool is_same = true;
	ll mn = 1e9, mx = 0;
	for (int i = 0; i < n; i++)
	{
		x.insert({seg[i][0], seg[i][2], seg[i][1]});
		y.insert({seg[i][1], seg[i][2], seg[i][0]});
		z.insert(seg[i]);
		//if start and end are not same
		mn = min(seg[i][0], mn);
		mx = max(seg[i][1], mx);
		auto p = x.lower_bound({mn, 0, 0});
		ll cost = (*p)[1];
		p = y.lower_bound({mx, 0, 0});
		cost += (*p)[1];
		//if start and end are the same
		ll c2 = 1e18;
		p = z.lower_bound({mn, mx, 0});
		if(p != z.end() && (*p)[0] == mn && (*p)[1] == mx)
			c2 = (*p)[2];
		cout << min(cost, c2) << "\n";
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
	}
	return 0;
}