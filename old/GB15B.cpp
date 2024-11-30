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

bool check(vector<int> first, vector<int> second)
{
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		if(first[i] < second[i])
			cnt++;
	}
	if(cnt > 2)
		return true;
	else
		return false;
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int> (5));
	for (int i = 0; i < n; i++){
			cin >> arr[i];
	}
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if(check(arr[i], arr[index])){
			index = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if(i == index)
			continue;
		if(check(arr[i], arr[index]))
			return void(cout << "-1");
	}
	cout << index + 1;
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