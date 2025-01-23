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
	ll n, K;
	cin >> n >> K;
	string str;
	cin >> str;
	if(K > 24)
	{
		for (int i = 0; i < n; i++)
			cout << 'a';
		return;
	}
	int k = K;
	char mx = 'a';
	for (int i = 0; i < n && k > 0; i++)
	{
		if (mx < str[i])
		{
			char change;
			if (k >= (int(str[i] - mx))) {
				k = k -  int(str[i] - mx);
				change = 'a';
			}
			else {
				change = str[i] - k;
				k = 0;
			}
			mx = str[i];
			for (int j = i + 1; j < n; j++)
			{
				if (str[j] <= str[i])
					str[j] = min(change, str[j]);
			}
			str[i] = change;
		}
	}
	cout << str;
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