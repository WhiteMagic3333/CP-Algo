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

ll not_actual_combination_function(ll i)
{
	if(i < 2)
		return 0;
	return (i * (i - 1)) / 2LL;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	vector<ll> cnt(1e6 + 1, 0);
	//step 1 find frequency of each element
	for(int i = 0; i < n; i++)
	{
		cnt[arr[i]]++;
	}
	//step 2 find multiples of each element
	for (int i = 1; i <= 1e6; i++)
	{
		for (int j = 2 * i; j <= 1e6; j += i)
		{
			cnt[i] += cnt[j];
		}
	}
	//replace cnt[i] by (cnt[i])C(2)
	//here 2 is used because we have to count pairs
	//in case of triplets or a group of more numbers we will replace 2 by 3 or more
	for (int i = 1; i <= 1e6; i++)
	{
		cnt[i] = not_actual_combination_function(cnt[i]);//for pairs this returns nC2, for triplets use nC3
	}
	//inclusion exclusion princple used here
	//subtract cnt[i] by its multiples
	for (int i = 1e6; i > 0; i--)
	{
		for (int j = 2 * i; j <= 1e6; j += i)
			cnt[i] -= cnt[j];
	}
	cout << cnt[1];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}