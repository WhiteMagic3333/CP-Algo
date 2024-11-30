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
// order if all 3 present
// 2->3->2,2->2,3->2,2,3
// if 1 blue 1 green
// 2->3->2,3

int bgg(vector<ll> &a, ll h)
{
	int n = a.size();
	int i = 0;
	int choice = 3;
	while(i < n)
	{
		if(a[i] < h)
		{
			h += a[i] / 2;
			i++;
		}
		else
		{
			if(choice == 3)
			{
				h = h * 3;
			}
			else if(choice != 0)
			{
				h = h * 2;
			}
			else
				break;
			choice--;
		}
	}
	return i;
}

int gbg(vector<ll> &a, ll h)
{
	int n = a.size();
	int i = 0;
	int choice = 3;
	while(i < n)
	{
		if(a[i] < h)
		{
			h += a[i] / 2;
			i++;
		}
		else
		{
			if(choice == 2)
			{
				h = h * 3;
			}
			else if(choice != 0)
			{
				h = h * 2;
			}
			else
				break;
			choice--;
		}
	}
	return i;
}

int ggb(vector<ll> &a, ll h)
{
	int n = a.size();
	int i = 0;
	int choice = 3;
	while(i < n)
	{
		if(a[i] < h)
		{
			h += a[i] / 2;
			i++;
		}
		else
		{
			if(choice == 1)
			{
				h = h * 3;
			}
			else if(choice != 0)
			{
				h = h * 2;
			}
			else
				break;
			choice--;
		}
	}
	return i;
}

void solve()
{
	ll n, h;
	cin >> n >> h;
	vector<ll> a(n);
	cin >> a;
	ll temp = h;
	int blue = 1, green = 2;
	sort(a.begin(), a.end());
	//bgg
	int ans = max({bgg(a, h), gbg(a, h), ggb(a, h)});
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
		cout << "\n";
	}
	return 0;
}
		