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
	vector<ll> arr(3), ans(3);
	cin >> arr;
	vector<int> order(3);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){
		return arr[i] < arr[j];
	});

	if((arr[order[0]] + arr[order[1]]) > arr[order[2]])
	{
		ans[order[0]] = arr[order[0]] + arr[order[1]];
		ans[order[1]] = arr[order[1]];
		ans[order[2]] = arr[order[0]] + arr[order[1]] + arr[order[2]];
	}
	else
	{
		ans[order[0]] = (arr[order[2]] / arr[order[1]] + 1) * arr[order[1]] + arr[order[0]];
		ans[order[1]] = arr[order[1]];
		    ans[order[2]] = arr[order[2]];
	}
n}

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