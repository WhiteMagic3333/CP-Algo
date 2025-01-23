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
	//ok so lets define the dp states
	//dp[10][11] = min({dp[10][	, dp[10][11] })

	int a, b;
	cin >> a >> b;
	int mx = max(a, b);
	vector<vector<int>> dp(mx + 1, vector<int> (mx + 1, 1e5));
	for (int i = 1; i <= mx; i++)
	{
		for (int j = 1; j <= mx; j++)
		{
			if (i == 1 || j == 1)
				dp[i][j] = max(i, j) - 1;
			else if (i == j)
				dp[i][j] = 0;
			else
			{
				for (int k = 1; k < i; k++)
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
				for (int k = 1; k < j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}

		}
	}

	cout << dp[a][b];

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}