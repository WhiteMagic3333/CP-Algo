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

void clockwise(vector<int> &arr)
{
	swap(arr[0], arr[2]);
	swap(arr[2], arr[1]);
	swap(arr[2], arr[3]);
}

bool sorted(vector<int> &arr)
{
	if(arr[0] < arr[1] && arr[2] < arr[3] && arr[0] < arr[2] && arr[1] < arr[3])
		return true;
	return false;
}

void solve()
{
	vector<int> arr(4);
	cin >> arr;
	for (int i = 0; i < 5; i++)
	{
		if(sorted(arr))
			return void(cout << "YES");
		clockwise(arr);
		// cout << arr[0] << " " << arr[1] << "\n";
		// cout << arr[2] << " " << arr[3] <<"\n\n";
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