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

bool check(vector<array<int, 2>> &arr, int mid)
{
	ll left = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if(arr[i][1] >= left && arr[i][0] >= (mid - left - 1)){
			left++;
			if(left == mid)
				return true;
		}
	}
	return false;
}

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 2>> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];
	ll low = 1, high = n, ans = 0;
	while(low <= high)
	{
		ll mid = low + (high - low) / 2;
		if(check(arr, mid))
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