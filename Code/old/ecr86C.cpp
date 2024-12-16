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
//my ans also same no diff
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

ll lcm_find(ll a, ll b)
{
	ll g = __gcd(a, b);
	return (a * b) / g;
}

ll func(ll n, ll a, ll b)
{
	if(n < b)
		return 0;
	ll ans = n - b + 1;
	ll lcm = lcm_find(a, b);
	ll q = n / lcm;
	ans = ans - q;
	ans = ans - (q - 1) * (b - 1);
	ll extra = min((n % lcm), b - 1);
	ans = ans - extra; 
	return ans;
}

void solve()
{
	ll a, b, q;
	cin >> a >> b >> q;
	if (a > b)
		swap(a, b);
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		if (b % a == 0 || r < b)
		{
			cout << "0 ";
			continue;
		}
		ll ans = func(r, a, b) - func(l - 1, a, b);
		cout << ans << " ";
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
		cout << "\n";
	}
	return 0;
}