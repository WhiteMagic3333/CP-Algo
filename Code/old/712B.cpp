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

void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;

	vector<int> prefix_sum(n, 0);
	prefix_sum[0] = (a[0] == '1') ? 1 : 0;
	for (int i = 1; i < n; i++) {
		prefix_sum[i] = prefix_sum[i - 1];
		if (a[i] == '1') prefix_sum[i]++;
	}

	int flip = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (flip) 
			a[i] = (a[i] == '1' ? '0' : '1');
		if (a[i] != b[i]) {
			if ((i + 1) != prefix_sum[i] * 2) {
				cout << "NO";
				return;
			}
			flip ^= 1;
		}
	}

	cout << "YES";
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