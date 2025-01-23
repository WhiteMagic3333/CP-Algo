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

void display(vector<array<ll, 2>> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i][0] << " " << arr[i][1] << "\n";
	}
}

void solve()
{
	int n;
	cin >> n;
	vector<array<ll, 2>> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];
	sort(arr.begin(), arr.end(), [&](array<ll, 2> a, array<ll, 2> b){
		if(a[1] == b[1])
			return a[0] > b[0];
		return a[1] > b[1];
	});
	//display(arr);
	ll i = 0, j = n - 1, bought = 0, price = 0;
	while(i <= j)
	{
		if(bought >= arr[j][1]){
			bought += arr[j][0];
			price += arr[j][0];
			j--;
		}
		else{
			ll mn = min(arr[i][0], arr[j][1] - bought);
			bought += mn;
			price += 2 * mn;
			if(mn != arr[i][0]){
				arr[i][0] -= mn;
			}
			else
				i++;
		}
	}
	cout << price;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}