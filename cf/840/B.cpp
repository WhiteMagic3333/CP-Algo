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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> arr(n, vector<int> (2)); // health, pwr
	multiset<int> pwr;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0];//health
	for (int i = 0; i < n; i++){
		cin >> arr[i][1];//pwr
		pwr.insert(arr[i][1]);
	}
	sort(arr.begin(), arr.end());
	int damage = 0, i = 0;
	while(k > 0)
	{
		damage += k;
		while(i < n && arr[i][0] <= damage)
		{
			pwr.erase(pwr.find(arr[i][1]));
			i++;
		}
		if(i == n)
			return void(cout << "YES");
		ll reduce = *(pwr.begin());
		k -= reduce;
	}
	cout << "NO";
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