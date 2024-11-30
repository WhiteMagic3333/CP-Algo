
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
	string x, y;
	cin >> x >> y;
	int n = x.length();
	vector<char> a(n), b(n), arr(n, '?');
	for (int i = 0; i < n; i++)
	{
		a[i] = x[i];
		b[i] = y[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0, k = n - 1, turn = 1, last = n - 1;
	while (i <= last) {
		if (a[j] < b[k])
			arr[i++] = turn ? a[j++] : b[k--];
		else {
			int a_shift = (last - i + 2) / 2 - 1, b_shift = (last - i + 1) - (last - i + 2) / 2 - 1;
			if(!turn)
				swap(a_shift, b_shift);
			while(i <= last) {
				arr[last--] = turn ? a[j + a_shift--] : b[k - b_shift--];
				turn ^= 1;
			}
		}
		turn ^= 1;
	}
	for (char i : arr)
		cout << i;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}