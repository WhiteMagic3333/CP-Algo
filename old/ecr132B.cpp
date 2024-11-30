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
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	cin >> arr;
	vector<ll> pre(n, 0), post(n, 0);
	for (int i = 1; i < n; i++)
	{
		pre[i] = pre[i - 1];
		if(arr[i] < arr[i - 1])
			pre[i] += arr[i - 1] - arr[i];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		post[i] = post[i + 1];
		if(arr[i] < arr[i + 1])
			post[i] += arr[i + 1] - arr[i];
	}
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if(a < b)
			cout << pre[b] - pre[a] << "\n";
		else
			cout << post[b] - post[a] << "\n";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}