#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
using namespace std;
typedef long long ll;
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
	vector<int> a(n), b(n);
	cin >> a >> b;
	vector<int> freq(n + 1, 0);
	int i = n - 1, j = n - 1;
	while(i >= 0)
	{
		while(j != 0 && b[j] == b[j - 1]){
			freq[b[j]]++;
			j--;
		}
		if(a[i] == b[j])
		{
			i--;
			j--;
			continue;
		}
		if(freq[a[i]] == 0)
			return void(cout << "NO");
		freq[a[i]]--;
		i--;
	}
	cout << "YES";
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