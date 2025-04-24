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

ll rnd(int digits) {
	//for upto 1e18
	digits = min(digits, 18);
	int d = max(rand() % (digits + 1), 2);
	if (d == 18) {
		return 1e18;
	}
	ll num = 0;
	for (int i = 0; i < d; i++) {
		num = num * 10 + (rand() % 9);
		if (i == 0) {
			num = max(1LL, num);
		}
	}
	return num;
}
 
void solve()
{
	srand(time(0));
	ll lim = 1e18;
	ll r = rnd(3);
	ll l = rnd(3);
	if (l > r) {
		swap(l, r);
	}
	cout << l << " " << r;
	// cout << "1 \n" << n << "\n";
	
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}