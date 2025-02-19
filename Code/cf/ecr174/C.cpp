#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#define MAXN 250001
using namespace std;
typedef long long ll;
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

ll mod = 998244353;

long long ap_sum(ll n) {
	return ((n * (n + 1)) / 2LL) % mod;
}

struct FenwickTree {
    long long BIT1[MAXN], BIT2[MAXN];
    int n;

    FenwickTree(int size) { n = size; }

    void updateBIT(long long BIT[], int index, long long val) {
        while (index <= n) {
            BIT[index] += ap_sum(val);
            BIT[index] %= mod;
            index += index & -index;
        }
    }

    void rangeUpdate(int l, int r, long long val) {
        updateBIT(BIT1, l, val);
        updateBIT(BIT1, r + 1, -val);
        updateBIT(BIT2, l, val * (l - 1));
        updateBIT(BIT2, r + 1, -val * r);
    }

    long long queryBIT(long long BIT[], int index) {
        long long sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }

    long long prefixSum(int index) {
        return queryBIT(BIT1, index) * index - queryBIT(BIT2, index);
    }

    long long rangeQuery(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};


void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	cin >> arr;
	FenwickTree bit(n);
	int sz = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			sz++;
		} else if (arr[i] == 2) {
			bit.rangeUpdate(1, sz, 1);
		} else {
			ans += bit.prefixSum(sz - 1);
		}
	}
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