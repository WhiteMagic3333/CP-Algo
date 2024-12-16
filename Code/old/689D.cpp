#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<set>
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

void fun(set<ll> &ans, vector<ll> &arr, vector<ll> &pre,  int i, int j)
{
	ans.insert(pre[j] - pre[i] + arr[i]);
	ll mid = (arr[i] + arr[j]) / 2;
	int index = int(upper_bound(arr.begin(), arr.end(), mid) - arr.begin()) - 1;
	if(index == j)
		return;
	fun(ans, arr, pre, i, index);
	fun(ans, arr, pre, index + 1, j);
}	

void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n), pre(n);
	cin >> arr;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
		pre[i] = arr[i] + (i != 0 ? pre[i - 1] : 0);
	set<ll> ans;
	fun(ans, arr, pre, 0, n - 1);
	while(q--)
	{
		ll s;
		cin >> s;
		if(ans.find(s) != ans.end())
			cout << "YES\n";
		else
			cout << "NO\n";
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
	}
	return 0;
}