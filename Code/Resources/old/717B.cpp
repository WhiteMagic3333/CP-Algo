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

bool check(int l, int m, int r)
{
	if (l == m && m == r)
		return true;
	return false;
}

void solve()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans ^= arr[i];
	if (ans == 0LL)
		cout << "YES";
	else
	{
		int exor = 0;
		for (int i = 0; i < n; i++)
		{
			exor = exor ^ arr[i];
			if (exor == ans)
			{
				int count = 0, inner_exor = 0;
				for (int j = i + 1; j < n; j++)
				{
					inner_exor = inner_exor ^ arr[j];
					if(inner_exor == ans)
						count++;
				}
				if(count)
					return void(cout << "YES");
			}
		}
		cout << "NO";
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