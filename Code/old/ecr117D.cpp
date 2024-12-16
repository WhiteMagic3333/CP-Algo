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

void fun(vector<vector<bool>> &arr, int a, int b)
{
	if(arr[a][b] || a < 0 || b < 0)
		return;
	arr[a][b] = true;
	arr[b][a] = true;
	fun(arr, a, abs(a - b));
	fun(arr, b, abs(a - b));
}

void solve()
{
	ll a, b, x;
	cin >> a >> b >> x;
	if(a < b)
		swap(a, b);
	vector<vector<bool>> arr(a + 1, vector<bool> (a + 1, false));
	fun(arr, a, b);
	set<int> ans;
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			if(arr[i][j])
			{
				ans.insert(i);
				ans.insert(j);
			}
		}
	}
	for (int i : ans)
		cout << i << " ";
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