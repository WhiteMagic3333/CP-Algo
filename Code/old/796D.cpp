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
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0;
	if(k <= n)
	{
		for (int i = 0; i < k; i++)
			ans += arr[i];
		ll cur = ans;
		for (int i = k; i < n; i++){
			cur += arr[i] - arr[i - k];
			ans = max(ans, cur);
		}
		ans += (k - 1) * (k) / 2;
	}
	else{
		ans += accumulate(arr.begin(), arr.end(), 0LL);
		ans += (k * (k - 1)) / 2 - (k - n) * (k - n + 1) / 2 + k - n;
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