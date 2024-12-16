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

vector<ll> fac(1e6 + 1), inv_fac(1e6 + 1);

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void pre()
{
	fac[0] = inv_fac[0] = 1;
	for (ll i = 1; i <= 1e6; i++)
	{
		fac[i] = (i * fac[i - 1]) % mod;
		inv_fac[i] = (inv_fac[i - 1] * binpow(i, mod - 2, mod)) % mod;
	}
}

void solve()
{
	string str;
	cin >> str;
	vector<ll> freq(26);
	for (int i = 0; i < str.length(); i++)
		freq[int(str[i] - 'a')]++;
	ll ans = fac[str.length()];
	for (int i = 0; i < 26; i++)
	{
		if(freq[i] > 1)
			ans = (ans * inv_fac[freq[i]]) % mod;
	}
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	pre();
	solve();
	return 0;
}