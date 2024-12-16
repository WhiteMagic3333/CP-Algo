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
 
void solve()
{
	int n;
	cin >> n;
	int sum = (n * (n + 1)) / 2;
	if (sum % 2)
		return void(cout << "0");
	vector<vector<ll>> dp(n + 1, vector<ll> (sum / 2 + 1, 0LL));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int x = 0; x <= sum / 2; x++)
		{
			dp[i][x] = (((x < i) ? 0LL : dp[i - 1][x - i]) + dp[i - 1][x]) % mod;
		}
	}
	//cout << dp[n][sum / 2] * (mod + 1) / 2 %  mod;
	cout << dp[n][sum / 2] * (mod + 1) / 2 % mod;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}