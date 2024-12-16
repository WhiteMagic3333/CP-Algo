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

ll neg_inf = -1e18;

vector<vector<ll>> dp(5000, vector<ll> (5000, neg_inf));
vector<ll> pre_sum(5000);

ll fun(vector<ll> & arr, int i, int j)
{
	if(i == j)
		return arr[i];
	if( dp[i][j] != neg_inf)
		return dp[i][j];
	ll sum = pre_sum[j] - pre_sum[i] + arr[i];
	return dp[i][j] = max(sum - fun(arr, i + 1, j), sum - fun(arr, i, j - 1));
}
void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	pre_sum[0] = arr[0];
	for(int i = 1; i < n; i++)
		pre_sum[i] = pre_sum[i - 1] + arr[i];
	cout << fun(arr, 0, n - 1);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}