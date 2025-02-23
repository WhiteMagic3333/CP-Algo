#include <numeric>
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
 
void solve()
{
	int n;
	vector<ll> arr(n);
	cin >> arr;
	vector<ll> f_left(n + 5, 0), f_right(n + 5, 0), f(n + 5, 0);
	for (int i = 0; i < n; i++) {
		if (arr[i] <= n + 1) {
			f[arr[i]]++;
		}
	}
	ll mex = 1e9;
	for (int i = 0; i <= n + 1; i++) {
		if (f[i] == 0) {
			mex = i;
			break;
		}
	}
	ll l = 0, r = n - 1;
	ll l_mex = 0, r_mex = 0, mid_mex = 1e9;
	ll l_sum = 0, r_sum = 0;
	while (l < n) {
		l_sum += arr[l];
		if (arr[l] <= n + 1) {
			f_left[l]++;
			f[l]--;
			if (f[l] == 0) {
				mid_mex = min(mid_mex, l);
			}
			while (f_left[l_mex] > 0) {
				l_mex++;
			}
			if (l_mex == mex) {
				break;
			}
		}
		l++;
	}
	while (r >= 0) {
		r_sum += arr[r];
		if (arr[r] <= n + 1) {
			f_right[r]++;
			f[r]--;
			if (f[r] == 0) {
				mid_mex = min(mid_mex, r);
			}
			while (f_right[r_mex] > 0) {
				r_mex++;
			}
			if (r_mex == mex) {
				break;
			}
		}
		r--;
	}
	if (mid_mex >= mex && l <= r) {
		ll mid_sum = accumulate(arr.begin(), arr.end(), 0LL);
		mid_sum = mid_sum - l_sum - r_sum;
		ll min_ans = l_sum + r_sum - mid_sum;
		//two pointers
		int low = l, high = r;
		while (high > l + 1) {
			
		}

	} else {
		cout << "-1 -1";
	}
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