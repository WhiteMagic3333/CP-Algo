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
	vector<array<int, 5>> arr(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			int index = int(str[j] - 'a');
			arr[i][index]++;
		}
	}
	int ans = 0;
	for (int e = 0; e < 5; e++)
	{
		sort(arr.begin(), arr.end(), [&] (array<int, 5> a, array<int, 5> b) {
			ll total_a = a[e] * 2 - (a[0] + a[1] + a[2] + a[3] + a[4]);
			ll total_b = b[e] * 2 - (b[0] + b[1] + b[2] + b[3] + b[4]);

			return total_a > total_b;
		});
		int freq = 0, tot = 0;
		for (int i = 0; i < n; i++)
		{
			freq += arr[i][e];
			for (int j = 0; j < 5; j++)
				tot += arr[i][j];
			if (freq * 2 > tot)
				ans = max(ans, i + 1);
		}
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