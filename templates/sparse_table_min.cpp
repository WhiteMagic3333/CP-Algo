#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<numeric>
#include<math.h>
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
 
int K = 32;
 
vector<vector<ll>> st(2e5 + 1, vector<ll> (K + 1));

ll fun(ll L, ll R)
{
	ll j = log2(R - L + 1);
	ll minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
	return minimum;
}
 
void solve()
{
	ll N, Q;
	cin >> N >> Q;
	vector<ll> array(N);
	cin >> array;
	for (int i = 0; i < N; i++)
		st[i][0] = array[i];
	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1LL << j) <= N; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);

	while (Q--)
	{
		ll l, r;
		cin >> l >> r;
		cout << fun(l - 1, r - 1) << "\n";
	}
 
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}