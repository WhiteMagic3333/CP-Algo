#include <iostream>
#include <algorithm>
#include <numeric>
typedef long long ll;
using i64 = long long;
using namespace std;
constexpr int P = 1000000007;

ll lcm(ll a, ll b)
{
	ll g = __gcd(a, b);
	ll lc = (a * b) / g;
	return lc;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		i64 n;
		std::cin >> n;
		int ans = 0;
		for (i64 x = 1, i = 1; x <= n; x = lcm(i, x), i++) {
			ans = (ans + n / x) % P;
		}
		std::cout << ans << "\n";
	}
	return 0;
}