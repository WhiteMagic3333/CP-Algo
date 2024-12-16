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
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0;
	if(n % 2)
	{
		for (int i = 1; i < n; i += 2){
			ll mx = max(arr[i - 1], arr[i + 1]);
			if(mx >= arr[i])
				ans += mx - arr[i] + 1;
		}
	}
	else{
		vector<ll> pre(n, 0), post(n + 1, 0);//0 based at 1, 3, 5
		for (int i = 1; i < n - 1; i += 2)
		{
			ll mx = max(arr[i - 1], arr[i + 1]);
			pre[i] = pre[i - 1];
			if(mx >= arr[i])
				pre[i] += mx - arr[i] + 1;
			pre[i + 1] = pre[i];
		}
		pre[n - 1] += pre[n - 2];
		int j = n - 2;
		ans = 1e18;
		if(j % 2)
			j--;
		for ( ; j > 0; j -= 2)
		{
			ll mx = max(arr[j - 1], arr[j + 1]);
			post[j] = post[j + 1];
			if(mx >= arr[j])
				post[j] += mx - arr[j] + 1;
			post[j - 1] = post[j];
		}
		post[0] = post[1];
		// cout << pre << post;
		for (int i = 1; i < n; i++){
			ans = min(ans, pre[i - 1] + post[i]);
			ans = min(ans, post[i - 1] + pre[i]);
		}
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