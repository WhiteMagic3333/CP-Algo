#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<stack>
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

ll fun(vector<array<ll, 3>> &arr, int i, ll prev)
{
	if (i < 0)
		return 0;
	ll include = 0;
	if (arr[i][1] < prev)
		include = fun(arr, i - 1, arr[i][0]) + arr[i][2];
	ll discard = fun(arr, i - 1, prev);
	return max(include, discard);
}


void solve()
{
	int n;
	cin >> n;
	vector<array<ll, 3>> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i][1] >> arr[i][0] >> arr[i][2];
	ll ans = 0;
	sort(arr.begin(), arr.end());

	vector<ll> last_day_index(n, -1);
	for (int i = 1; i < n; i++)
	{
		array<ll, 3> jk;
		jk[0] = arr[i][1];
		jk[1] = 0LL;
		jk[2] = 0LL;
		int index = lower_bound(arr.begin(), arr.end(), jk) - arr.begin() - 1;
		if(index >= 0)
			last_day_index[i] = index;
	}

	vector<ll> dp(n, 0);
	dp[0] = arr[0][2];
	for (int i = 1; i < n; i++)
	{
		if(last_day_index[i] != -1)
			dp[i] = dp[last_day_index[i]] + arr[i][2];
		else
			dp[i] = arr[i][2];
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[n - 1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}