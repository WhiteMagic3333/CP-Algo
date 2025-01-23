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

pair<ll, ll> fun(vector<ll> &arr, vector<pair<ll, ll>> &dp, vector<bool> &present, ll &w, int j)
{
	if(present[j])
		return dp[j];
	pair<ll, ll> val = {20, 1e10};
	for (int i = 0; i < arr.size(); i++)
	{
		if((1 << i)&j){
			pair<ll, ll> rem = fun(arr, dp, present, w, (1 << i) ^ j);
			rem.second += arr[i];
			if(rem.second > w){
				rem.first++;
				rem.second = arr[i];
			}
			val = min(val, rem);
		}
	}
	present[j] = true;
	return dp[j] = val;
}

void solve()
{
	int n;
	cin >> n;
	ll w;
	cin >> w;
	vector<ll> arr(n);
	cin >> arr;
	ll lim = 1 << n;
	vector<pair<ll, ll>> dp(lim);//{no of lifts, total weight of the last one}
	vector<bool> present(lim, false);
	dp[0] = {1, 0};
	present[0] = true;
	for (int i = 0; i < lim; i++) {
		dp[i] = fun(arr, dp, present, w, i);
		//cout <<i << " : " << dp[i].first << " " << dp[i].second << "\n";
	}
	cout << dp[lim - 1].first;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}