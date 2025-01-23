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
	ll n, a, b, score = 0;
	cin >> n >> a >> b;
	vector<ll> arr(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int i = 1, pos = 0;
	while (i <= n)
	{
		ll direct = (arr[i] - arr[pos]) * b;
		ll indirect = (arr[i - 1] - arr[pos]) * a + (arr[i] - arr[i - 1]) * b;
		cout << direct << " " << indirect << "\n";
		if ( direct < indirect) {
			score += direct;
			cout << "Conquer " << direct << "\n";
		}
		else {
			score += indirect;
			pos = i - 1;
			cout << "Move & Conquer " << indirect << "\n";
		}
		i++;
	}
	cout << score;

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