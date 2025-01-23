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

bool fun(ll n, ll m, vector<ll> &arr)
{
	ll cnt = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		ll cur = (arr[i] / n);
		if (cur > 1)
		{
			cnt = cnt + cur;
			if (cnt >= m)
				return true;
			if (cnt == m - 1)
			{
				cnt -= cur;
				if (cur != 2)
					cnt = m - 2;
			}
		}
	}
	return false;
}

void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> arr(k);
	cin >> arr;
	sort(arr.begin(), arr.end());
	if (fun(n, m, arr) || fun(m, n, arr))
		cout << "YES";
	else
		cout << "NO";

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, cnt = 1;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}