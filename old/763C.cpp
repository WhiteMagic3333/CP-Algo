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


bool valid( vector<ll> arr, ll mid)
{
	int n = arr.size();
	vector<ll> added(n, 0);
	for(int i = n - 1; i > 1; i--)
	{
		if(added[i] >= mid)
		{
			added[i - 2] += arr[i] / 3 * 2;
			added[i - 1] += arr[i] / 3;
			arr[i] = arr[i] % 3;
		}
		else{
			int new_mid = mid - added[i];
			int first = max(0LL, (arr[i] - new_mid)) / 3 * 2;
			int second = max(0LL, (arr[i] - new_mid)) / 3;
			added[i - 2] += first;
			added[i - 1] += second;
			arr[i] = arr[i] - first - second;
		}
	}
	// cout << arr;
	// cout << added;
	for(int i = 0; i < n; i++)
	{
		if( (arr[i] + added[i]) < mid)
			return false;
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll low = 0, high = 1e9, ans = 1e9;
	while(low <= high)
	{
		ll mid = low + (high - low) / 2;
		if( valid(arr, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
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