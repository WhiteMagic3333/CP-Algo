#include <vector>
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

int far_right(vector<array<int, 2>> &mn, int x){
	int low = 0, high = mn.size() - 1;
	//descending order sorted with their idx
	int idx = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if (mn[mid][0] < x) {
			idx = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return idx == -1 ? idx : mn[idx][1];
}

 
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n), pre(n);
	cin >> arr;
	pre[0] = arr[0];
	for (int i = 1; i < n; i++) {
		pre[i] = max(pre[i - 1], arr[i]);
	}
	vector<int> ans(n);
	vector<array<int, 2>> mn;
	for (int i = n - 1; i >= 0; i--) {
		if (mn.size() == 0 || mn.back()[0] > arr[i]) {
			mn.push_back({arr[i], i});
		}
		if (pre[n - 1] == pre[i]) {
			ans[i] = pre[n - 1];
		} else {
			int fr = max(i, far_right(mn, pre[i]));
			ans[i] = max(ans[fr], pre[fr]);
		}
	}
	cout << ans;
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
	}
	return 0;
}