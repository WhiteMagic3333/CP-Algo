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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	cin >> arr;
	ll ans = 0, left = 0, cur = 0;
	for (int j = 1; j < 35; j++)
	{
		if (j <= n)
			cur += (arr[j - 1] / (1LL << j));
	}
	ans = max(ans, cur);
	for (int i = 0; i < n; i++)
	{
		cur = 0;
		
		left = left + arr[i] - k;
		for (int j = 1; j < 35; j++)
		{
			if ((i + j) < n)
				cur += (arr[i + j] / (1LL << j));
		}
		ans = max(ans, left + cur);
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