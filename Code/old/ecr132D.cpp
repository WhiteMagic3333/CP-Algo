#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int K = 32;

vector<vector<ll>> st(2e5 + 1, vector<ll> (K + 1));
vector<ll> lg(2e5 + 1);

void pre()
{
    lg[1] = 0;
    for (int i = 2; i <= 2e5; i++)
        lg[i] = lg[i / 2] + 1;
}

ll query(ll L, ll R)
{
    ll j = lg[R - L + 1];
    ll maximum = max(st[L][j], st[R - (1LL << j) + 1][j]);
    return maximum;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(m);
	cin >> arr;
	ll q;
	cin >> q;
	for (int i = 0; i < m; i++)
        st[i][0] = arr[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1LL << j) <= m; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
	while(q--)
	{
		ll rr, rc, fr, fc, k;
		cin >> rr >> rc >> fr >> fc >> k;
		if(rc > fc){
            swap(rr, fr);
            swap(rc, fc);
        }
        bool f = true;
        if((abs(rr - fr) % k || abs(rc - fc) % k))
            f = false;
        ll mx_high = rr + ((n - rr) / k) * k;
		ll between = query(rc - 1, fc - 1);
		if(mx_high <= between){
			f = false;
		}
		if(f)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    pre();
	solve();
	return 0;
}