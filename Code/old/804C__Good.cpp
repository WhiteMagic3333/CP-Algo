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

int mex(vector<int> &arr, int i, int j)
{
	int n = arr.size();
	vector<bool> used(n + 1, false);
	int mex = 0;
	for (int x = i; x <= j; x++) {
		used[arr[x]] = true;
		while (used[mex])
			mex++;
	}
	return mex;
}

void solve()
{
	int n, count = 0;
	cin >> n;
	vector<int> arr(n), fake(n);
	cin >> arr;
	iota(fake.begin(), fake.end(), 0);
	do {
		bool val = true;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
			{
				if (mex(arr, i, j) != mex(fake, i, j)) {
					val = false;
					break;
				}
			}
			if (!val)
				break;
		}
		if (val)
			count++;
	} while (next_permutation(fake.begin(), fake.end()));
	cout << count;
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