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
	vector<ll> a(n), b(n);
	cin >> a >> b;
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];
	//odd size
	for (int center = 0; center < n; center++)
	{
		ll cur = sum;
		for (int i = 0; (center + i) < n && (center - i) >= 0; i++)
		{
			cur -= (a[center - i] * b[center - i] + a[center + i] * b[center + i]);
			cur += (a[center + i] * b[center - i] + a[center - i] * b[center + i]);
			ans = max(ans, cur);
		} 
	}
	//even size
	for (int center = 0; center < n; center++)
	{
		ll cur = sum;
		for (int i = 0; (center + i + 1) < n && (center - i) >= 0; i++)
		{
			cur -= (a[center - i] * b[center - i] + a[center + i + 1] * b[center + i + 1] );
			cur += (a[center + i + 1] * b[center - i] + a[center - i] * b[center + i + 1] );
			ans = max(ans, cur);
		}
	}
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}