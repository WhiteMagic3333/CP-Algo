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

bool check(ll c, ll small, ll large, ll rem)
{
	if (c >= (small + rem) && (c <= large))
	{
		c -= (small + rem);
		if ( c % small == 0)
			return true;
	}
	return false;
}

void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;
	if (c == a || c == b)
		return void(cout << "YES");
	if (a < b)
		swap(a, b);
	vector<ll> arr;
	arr.push_back(a);
	arr.push_back(b);
	int last = 1;
	while (arr[last] != 0)
	{
		ll cur = arr[last - 1] % arr[last];
		if (c == cur)
			return void(cout << "YES");
		if (check(c, arr[last], arr[last - 1], cur))
			return void(cout << "YES");
		arr.push_back(cur);
		last++;
	}
	cout << "NO";
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