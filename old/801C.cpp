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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int> (m)), mx(n, vector<int> (m, 0)), mn(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if ((n + m - 1) % 2)
		return void(cout << "NO");
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (i == n - 1 && j == m - 1) {
				mn[i][j] += arr[i][j] == 1;
				mx[i][j] += arr[i][j] == 1;
				continue;
			}
			else if (i == n - 1) {
				mx[i][j] = mx[i][j + 1];
				mn[i][j] = mn[i][j + 1];
			}
			else if (j == m - 1) {
				mx[i][j] = mx[i + 1][j];
				mn[i][j] = mn[i + 1][j];
			}
			else {
				mx[i][j] = max(mx[i + 1][j], mx[i][j + 1]);
				mn[i][j] = min(mn[i + 1][j], mn[i][j + 1]);
			}

			mn[i][j] += arr[i][j] == 1;
			mx[i][j] += arr[i][j] == 1;
		}
	}
	// for (int i = 0; i < n; i++)
	// 	cout << mn[i];
	// cout << '\n';
	// for (int i = 0; i < n; i++)
	// 	cout << mx[i];

	int req = (m + n - 1) / 2;
	if (req >= mn[0][0] && req <= mx[0][0])
		cout << "YES";
	else
		cout << "NO";
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