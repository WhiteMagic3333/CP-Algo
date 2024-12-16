#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<math.h>
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
 
vector<ll> arr;

void pre()
{
	for (ll a = 3; a < 1e5 + 1; a += 2)
	{
		ll b = (a * a - 1) / 2LL;
		ll c = sqrt(b * b + a * a);
		arr.push_back(c);
	}
}

void solve()
{
	int n;
	cin >> n;
	cout << upper_bound(arr.begin(), arr.end(), n) - arr.begin();

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	pre();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}