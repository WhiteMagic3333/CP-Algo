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

void fun(ll &extra, vector<int> &arr, int k)
{
	int n = arr.size();
	vector<ll> rem(k, 0);
	for (int i = 0; i < n; i++)
		rem[(arr[i] % k)]++;
	rem[0] = rem[0] % 2;
	int i = 1, j = k - 1;
	while (i <= j)
	{
		// cout << rem;
		if(i == j)
		{
			extra += ((i * 2) % k) * (rem[i] / 2);
			rem[i] = rem[i] % 2;
			break;
		}
		if((i + j) < k)
		{
			i++;
			continue;
		}
		int mn = min(rem[i], rem[j]);
		rem[i] -= mn;
		rem[j] -= mn;
		extra += mn * ( (i + j) % k);
		if (rem[j] == 0)
		{
			j--;
		}
		else
			i++;

	}
	// cout << rem;
	for (int i = 0; i < k; i++)
		extra += (rem[i] * i);
}


void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	cin >> arr;
	ll sum = accumulate(arr.begin(), arr.end(), 0LL);
	ll extra = 0;
	fun(extra, arr, k);
	// cout << extra << " ";
	// cout << sum << " ";
	cout << (sum - extra) / k;
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