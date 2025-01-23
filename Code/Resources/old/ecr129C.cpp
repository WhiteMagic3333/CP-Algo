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
	vector<int> a(n), b(n);
	vector<array<int, 2>> ans;
	cin >> a >> b;
	for( int i = 0; i < n; i++)
	{
		for( int j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swap(b[j], b[j + 1]);
				ans.push_back({j, j + 1});
			}
			else if(a[j] == a[j + 1] && b[j] > b[j + 1])
			{
				swap(a[j], a[j + 1]);
				swap(b[j], b[j + 1]);
				ans.push_back({j, j + 1});
			}
		}
	}
	if((is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())))
	{
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i][0] + 1<< " " << ans[i][1] + 1 << "\n";
		}
	}
	else
		cout << "-1\n";
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