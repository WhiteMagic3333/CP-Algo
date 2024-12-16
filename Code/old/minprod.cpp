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

long long fun(vector<long long> &arr, int n, int m, long long k)
{
	int neg = 0, pos = 0, zeroes = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
			pos++;
		else if (arr[i] < 0)
			neg++;
		else
			zeroes++;
	}
	bool f = false;

	if ((neg % 2 == 1) || zeroes)
		f = true;

	if (zeroes > m)
		return 0;

	multiset<long long> st;
	for (int i = 0; i < n; i++)
		if (arr[i] != 0)
			st.insert(abs(arr[i]));

	if (zeroes)
	{
		m = m - zeroes;
		if (neg % 2 == 0)
		{
			st.insert((-1) * k);
			zeroes--;
		}
		while (zeroes)
		{
			st.insert(k);
			zeroes--;
		}
	}
	if (f == false)
	{
		while (m)
		{
			auto p = st.begin();
			long long cur = (*p) - k;//minus here
			st.insert(cur);
			st.erase(p);
			m--;
			if (cur < 0){
				f = true;
				auto p = st.begin();
				long long cur = abs(*p);
				st.insert(cur);
				st.erase(p);
				break;
			}
		}
	}
	while (m)
	{
		auto p = st.begin();
		long long cur = (*p) + k;//plus here
		st.insert(cur);
		st.erase(p);
		m--;
	}
	long long p = 1, mod = 1e9 + 7;
	for (long long i : st)
	{
		p = (p * i) % mod;
	}
	return p;
}

void solve()
{
	long long n, k, m;
	cin >> n >> k >> m;
	vector<long long> arr(n);
	cin >> arr;
	cout << fun(arr, n, m, k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}