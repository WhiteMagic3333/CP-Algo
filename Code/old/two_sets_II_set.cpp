#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<set>
#include<unordered_map>
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
	ll sum = (n * (n + 1)) / 2;
	if (sum % 2)
		return void(cout << "0");
	unordered_map<ll, ll> ma;
	ma[1] = 1;
	ll i = 2;
	while(i <= n)
	{
		unordered_map<ll, ll> ta;
		ta[i] = 1;
		for (auto p : ma)
			ta[i + p.first] = (ta[i + p.first] + ma[p.first]) % mod;

		for (auto p : ta)
			ma[p.first] = (ma[p.first] + ta[p.first]) % mod;
		i++;
	}
	cout << ma[sum / 2] / 2 << "\n";
	

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}