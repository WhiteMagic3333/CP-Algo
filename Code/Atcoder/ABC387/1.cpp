#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
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

vector<int> getMaxElementIndexes(vector<int> &a, vector<int> &r) {
	vector<int> ans;
	int n = a.size();
	int lg = -1;
	int in = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > lg) {
			lg = a[i];
			in = i;
		}
	}
	for (auto &shift : r) {
		int i = in - shift;
		i = ((i % n) + n) % n;
		ans.push_back(i);
	}
	return ans;
}

 
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	int m;
	cin >> m;
	vector<int> rotate(m);
	cin >> rotate;
	vector<int> ans = getMaxElementIndexes(arr, rotate);
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}