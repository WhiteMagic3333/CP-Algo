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
 
vector<ll> palin;
vector<ll> dp(4e5 + 5);
bool palindrome(ll n)
{
	ll rev = 0;
	ll temp = n;
	while(n)
	{
		int d = n % 10;
		rev = rev * 10 + d;
		n = n / 10;
	}
	if(rev == temp)
		return true;
	else
		return false;
}

void precal()
{
	for (int i = 1; i < 4e4 + 1; i++)
	{
		if(palindrome(i * 1LL))
			palin.push_back(i * 1LL);
	}
	dp[0] = 1LL;
	for (int i = 0; i < palin.size(); i++)
	{
		for(int j = 1 ; j <= 4e4; j++)
		{
			if(palin[i] > j)
				continue;
			dp[j] = (dp[j] + dp[j - palin[i]]) % mod;
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	cout << dp[n];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	precal();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}