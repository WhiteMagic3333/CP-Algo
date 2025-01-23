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

int answer(string a, string b, int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			ans++;
	return ans;
}

void solve()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int a_ones = count(a.begin(), a.end(), '1'), b_ones = count(b.begin(), b.end(), '1');
	if ( !( a_ones == b_ones || (1 + (n - a_ones)) == b_ones))
		return void(cout << "-1");

	int ans = 1e5;
	if(a_ones == b_ones)
		ans = answer(a, b, n);
	if((1 + (n - a_ones)) == b_ones)
	{
		//10
		for (int i = 0; i < n; i++){
			if(a[i] == '1' && b[i] == '0'){
				string converted_a(n,' ');
				for (int j = 0; j < n; j++){
					converted_a[j] = (a[j] == '1' ? '0' : '1');
				}
				converted_a[i] = a[i];
				ans = min(answer(converted_a, b, n) + 1, ans);
				break;
			}
		}
		for (int i = 0; i < n; i++){
			if(a[i] == '1' && b[i] == '1'){
				string converted_a(n,' ');
				for (int j = 0; j < n; j++){
					converted_a[j] = a[j] == '1' ? '0' : '1';
				}
				converted_a[i] = a[i];
				ans = min(answer(converted_a, b, n) + 1, ans);
				break;
			}
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