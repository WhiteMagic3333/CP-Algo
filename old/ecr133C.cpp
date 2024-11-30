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

ll dif(ll a, ll b)
{
	return max(0LL, a - b);
}
void fun(vector<vector<ll>> &w, vector<vector<ll>> &arr, ll prev_blocks, int e, int i)
{
	int f = (e + 1) % 2;
	w[e][i] = max(0LL, w[e][i + 1] + dif(arr[f][i], arr[e][i + 1] + 1 + w[e][i + 1] + prev_blocks) + (arr[e][i + 1] - arr[e][i] - 1));
	if (i == 0)
		if (e == 0)
			w[e][i] = w[e][i + 1] + dif(arr[f][i], arr[e][i + 1] + 1 + w[e][i + 1] + prev_blocks) + arr[e][i + 1];
		else
			w[e][i] = -1;
}
void solve()
{
	int n;
	cin >> n;
	vector<vector<ll>> arr(2, vector<ll> (n));
	cin >> arr[0] >> arr[1];
	vector<vector<ll>> w(2, vector<ll> (n));//wait
	w[0][n - 1] = dif(arr[1][n - 1], arr[0][n - 1] + 1);//a - b
	w[1][n - 1] = dif(arr[0][n - 1], arr[1][n - 1] + 1);//a - b
	for (int i = n - 2; i >= 0; i--)
	{
		ll prev_blocks = (n - 1 - i) * 2 - 1;
		fun(w, arr, prev_blocks, 1, i);
		fun(w, arr, prev_blocks, 0, i);
	}
	ll ans = w[0][0] + 2 * n - 1;
	ll cur_time = 0, wait = 0;
	for (int i = 1; i < n; i++)
	{
		ll block_rem = (n - i) * 2 - 1;
		if (i % 2 == 0)
		{
			cur_time = max({cur_time + 2, arr[0][i - 1] + 2, arr[0][i] + 1});
			wait = dif(w[0][i], cur_time - arr[0][i] - 1);
		}
		else
		{
			cur_time = max({cur_time + 2, arr[1][i - 1] + 2, arr[1][i] + 1});
			wait = dif(w[1][i], cur_time - arr[1][i] - 1);
		}
		ans = min(ans, cur_time + wait + block_rem);
	}
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