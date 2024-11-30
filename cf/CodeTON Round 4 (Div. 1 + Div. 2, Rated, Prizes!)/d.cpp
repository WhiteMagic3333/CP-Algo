#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef uint64_t ll;
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

void make_jumps(ll a, ll b, ll n, ll &low, ll &high){
	//in n - 1 days
	if(n == 1){
		low = 1;
		high = a;
	}
	else if(n == 2){
		high = a - b + a;
		low = a + 1;
	}
	else if(n > 2){
		high = (n - 1LL) * (a - b) + a;
		low = (n - 2LL) * (a - b) + a + 1LL;
	}
}

ll days(ll a, ll b, ll height){
	ll mx = (1e18) / (a - b);
	ll low = 1, high = mx;
	ll ans = mx;
	while(low <= high){
		ll mid = low + (high - low) / 2LL;
		ll h = (mid - 1LL) * (a - b) + a;
		if(h >= height){
			ans = min(ans, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}

void check (ll a, ll b, ll low, ll high){
	ll dl = days(a, b, low);
	ll dh = days(a, b, high);
	// cout <<"\n"<< low << " " << high << "\n";
	if(dl == dh)
		cout << dl;
	else
		cout << "-1";
	cout << " ";
}
 
void solve()
{
	ll q;
	cin >> q;
	ll low = 1, high = 1e18;
	while(q--){
		ll type;
		cin >> type;
		if(type == 1){
			ll a, b, n;
			cin >> a >> b >> n;
			ll l, h;
			make_jumps(a, b, n, l, h);
			if(h < low || l > high)
				cout << "0 ";
			else{
				low = max(low, l);
				high = min(high, h);
				cout << "1 ";
			}
		}
		else{
			ll a, b;
			cin >> a >> b;
			check(a, b, low, high);
		}
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