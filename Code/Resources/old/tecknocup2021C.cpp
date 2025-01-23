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
	ll mn = *min_element(arr.begin(), arr.end());
	ll mx = *max_element(arr.begin(), arr.end());
	if (mn == mx)
		return void(cout << "0");
	int pd = -1, nd = -1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
			pd = arr[i] - arr[i - 1];
		else if(arr[i] < arr[i - 1])
			nd = arr[i - 1] - arr[i];
		else
			return void(cout << "-1");
	}
	if(pd == -1 || nd == -1)
		return void(cout << "0");
	int m = -1;
	for (int i = 1; i < n; i++){
		if(arr[i] < arr[i - 1]){
			m = arr[i - 1] + pd - arr[i];
			break;
		}
	}
	// validate
	for (int i = 1; i < n; i++)
	{
		if(((arr[i - 1] + pd) % m) != arr[i] || max(arr[i], arr[i - 1]) >= m)
			return void(cout << "-1");
	}
	cout << m << " " << pd;
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