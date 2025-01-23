#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
 
void solve()
{
	std::ifstream t("inputf.in");
	std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
	// cout << str;
	regex r("Difficulty\">\n(.*)");
 
    // flag type for determining the matching behavior
    // here it is for matches on 'string' objects
    smatch m;
 
    // regex_search() for searching the regex pattern
    // 'r' in the string 's'. 'm' is flag for determining
    // matching behavior.
    regex_search(str, m, r);
 
    // for each loop
    // for (auto x : m)
    //     cout << x << " ";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}