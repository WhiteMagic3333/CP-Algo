#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<numeric>
#define int long long
#define pb push_back
using namespace std;
int poww(int x, int y, int md)
{
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	int z = 1;
	while (y > 0)
	{
		if (y & 1)
			z *= x, z %= md;
		y = y >> 1;
		x *= x;
		x %= md;
	}
	return z;

}
const int mod = 1e9 + 7;
int lcm(int a, int b)
{
	return ((a / __gcd(a, b)) * b);
}
int inv(int x)
{
	//x%=mod;
	return poww(x, mod - 2, mod);
}
int fact[2000006];

int invv[2000006];

inline int fun(int a, int b)
{
	return (((fact[a] * invv[b]) % mod) * invv[a - b]) % mod;
}
void solve()
{

	int a, b;
	cin >> a >> b;
	int ans = fun(a + b - 1, a - 1);
	cout << ans << '\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i <= 2000000; i++)
	{
		fact[i] = fact[i - 1];
		fact[i] *= i;
		fact[i] %= mod;
	}
	invv[2000000] = inv(fact[2000000]) % mod;
	for (int i = 2000000; i >= 2; i--)
	{
		invv[i - 1] = (i * invv[i]) % mod;
	}
	invv[0] = 1;
	//  freopen("list.in","r",stdin);
	solve();
	return 0;
}