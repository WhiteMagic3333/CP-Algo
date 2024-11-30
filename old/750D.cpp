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

ll lcm(ll a, ll b)
{
	ll lcm_no = (a * b) / (__gcd(a, b));
	return lcm_no;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	cin >> arr;
	for (ll i : arr)
		sum += abs(i);
	ll index = 0, cmp = 1e9;
	for (int i = 0; i < n; i++)
	{
		ll upd_sum = sum - abs(arr[i]);
		ll lcm_no = lcm(upd_sum, abs(arr[i]));
		ll cnt = (lcm_no / upd_sum) * (n - 1) + (lcm_no / abs(arr[i]));
		if(cnt <= cmp)
		{
			for (int j = 0; j < n; j++)
			{
				int sign = arr[j] < 0 ? -1 : 1;
				if(j == i)
					cout << (lcm_no / abs(arr[i])) * sign * (-1) << " ";
				else
					cout << (lcm_no / upd_sum) * sign << " ";
			}
			return;
		}
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
		cout << "\n";
	}
	return 0;
}