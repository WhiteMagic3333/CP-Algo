#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<set>
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

void solve()
{
	//I have seen O(n^2) solutions earlier so trying out on O(Nlog(N))
	/*Although I saw on GFG that N Log(N) is possible so basically if I solve this
	then it would be considered as taking a hint
	*/
	int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> dp;
    dp.push_back(v[0]);
    for(int i = 1; i < n; i++){
        auto j = lower_bound(dp.begin(), dp.end(), v[i]);
        if(j==dp.end()){
            dp.push_back(v[i]);
        }
        else{
            *j = v[i];
        }
    }
    cout << dp.size() << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}