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
	vector<int> arr(n);
	cin >> arr;
	sort(arr.begin(), arr.end(), greater<int>());
	int old_gcd = arr[0];
	for (int i = 1; i < n; i++)
	{
		int cur_pos = i;
		int cur_gcd = __gcd(old_gcd, arr[cur_pos]);
		for (int j = i + 1; j < n; j++)
		{
			if (__gcd(old_gcd, arr[j]) > cur_gcd)
			{
				cur_pos = j;
				cur_gcd = __gcd(old_gcd, arr[cur_pos]);
			}
		}
		swap(arr[i], arr[cur_pos]);
		old_gcd = cur_gcd;
	}
	cout << arr;
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
	}
	return 0;
}