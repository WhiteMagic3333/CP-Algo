#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
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
int ct = 0;

ll min_diff(vector<ll> &a, int i, int j, ll e)
{
	ll mn = 1e18;
	for (int k = i; k < j; k++)
		mn = min(mn, abs(a[k] - e));
	return mn;
}

void solve()
{
	ct++;
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	cin >> a >> b;
	// 2 edges
	ll ans = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
	ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
	// 4 edges;
	ans = min(ans, min_diff(b, 1, n - 1, a[0]) + min_diff(b, 1, n - 1, a[n - 1]) + min_diff(a, 1, n - 1, b[0]) + min_diff(a, 1, n - 1, b[n - 1]));
	// 3 edges
	ans = min(ans, abs(a[0] - b[0]) + min_diff(a, 0, n - 1, b[n - 1]) + min_diff(b, 0, n - 1, a[n - 1]));
	ans = min(ans, abs(a[n - 1] - b[n - 1]) + min_diff(a, 1, n, b[0]) + min_diff(b, 1, n, a[0]));
	ans = min(ans, abs(a[0] - b[n - 1]) + min_diff(a, 0, n - 1, b[0]) + min_diff(b, 1, n, a[n - 1]));
	ans = min(ans, abs(a[n - 1] - b[0]) + min_diff(a, 1, n, b[n - 1]) + min_diff(b, 0, n, a[0]));
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