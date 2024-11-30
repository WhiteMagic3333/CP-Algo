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

void print(vector<array<int, 2>> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i][0] << " " << arr[i][1] << "\n";
	}
	cout << "\n";
}

int op(vector<array<int, 2>> &large, int rem)
{
	for (int i = 0; i < large.size(); i++)
	{
		int del = min(large[i][0], rem);
		large[i][0] -= del;
		rem -= del;
	}
	int ans = 0;
	for (int i = 0; i < large.size(); i++)
	{
		ans += large[i][0] / 2 + large[i][0] % 2;
	}
	return ans;
}

void solve()
{
	int n, l, r, a;
	cin >> n >> l >> r;
	map<int, int> left, right;
	for (int i = 0; i < l; i++)
	{
		cin >> a;
		left[a]++;
	}
	for (int i = 0; i < r; i++)
	{
		cin >> a;
		right[a]++;
	}
	int ans = 0, rem = 0;
	for (auto p : left)
	{
		int element = p.first;
		int frequency = min(p.second, right[element]);
		left[element] -= frequency;
		right[element] -= frequency;
		rem += frequency;
	}
	vector<array<int, 2>> small, large;
	for (auto p : left)
		if (p.second != 0)
			small.push_back({p.second, p.first});
	for (auto p : right)
		if (p.second != 0)
			large.push_back({p.second, p.first});

	sort(small.begin(), small.end());
	sort(large.begin(), large.end());
	// print(small);
	// print(lazrge);
	rem = min(l, r) - rem;
	ans += rem;
	if (l > r) {
		swap(small, large);
	}
	if (l != r)
		ans += op(large, rem);
	else
		ans += min(op(large, rem), op(small, rem));
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}