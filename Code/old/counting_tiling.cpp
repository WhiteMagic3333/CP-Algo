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

void display(vector<vector<ll>> &dp)
{
	int n = dp.size() - 1, m = dp[0].size() - 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void solve()
{
	int n, m;
	cin >> n >> m;
	if (n % 2 && m % 2)
		return void(cout << '0');
	vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			cout << i << " " << j << "\n";
				if(i % 2 && j % 2)
					dp[i][j] = 0;
				else
					dp[i][j] = () % mod;
				if(i <= m && j <= n)
					dp[j][i] = dp[i][j];
		}
		cout << "\n";
	}
	display(dp);
	cout << dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}