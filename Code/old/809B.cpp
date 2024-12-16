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
	vector<vector<int>> arr(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		arr[c].push_back(i);
	}
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int last_even = 0, last_odd = 0, ans = 0;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if(arr[i][j] % 2) {//odd
				dp[arr[i][j]] = dp[last_even] + 1;
				last_odd = arr[i][j];
			}
			else{
				dp[arr[i][j]] = dp[last_odd] + 1;
				last_even = arr[i][j];
			}
			ans = max(ans, dp[arr[i][j]]);
		}
		for (int j = 0; j < arr[i].size(); j++)
			dp[arr[i][j]] = 0;

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