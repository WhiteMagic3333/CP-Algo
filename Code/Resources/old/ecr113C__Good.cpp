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
#define mod 998244353
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

vector<ll> f(2e5 + 1), num(2e5 + 1), inv_f(2e5 + 1);


void InverseofNumber()
{
    num[0] = num[1] = 1;
    for (int i = 2; i <= 2e5 + 1; i++)
        num[i] = num[mod % i] * (mod - mod / i) % mod;
}
// Function to precompute inverse of factorials
void InverseofFactorial()
{
    inv_f[0] = inv_f[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= 2e5 + 1; i++)
        inv_f[i] = (num[i] * inv_f[i - 1]) % mod;
}

void precal()
{
    f[0] = 1;
    for (int i = 1; i <= 2e5 + 1; i++)
        f[i] = (f[i - 1] * i) % mod;
    InverseofNumber();
    InverseofFactorial();
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end());
    int largest_freq = 1, second_largest = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] == arr[i + 1])
            largest_freq++;
        else {
            second_largest = arr[i];
            break;
        }
    }

    if (!second_largest || largest_freq > 1)
        cout << f[n];
    else if ((arr[n - 1] - second_largest) > 1)
        cout << "0";
    else
    {
        int sl_freq = 0;
        for (int i = 0; i < n; i++)
            sl_freq += arr[i] == second_largest;

        ll ans = 0;// (REM + largest) + second_largest
        int rem = n - 1 - sl_freq;
        // cout << rem << " ";
        for (int i = 0; i <= rem; i++)
        {
            ll left = f[sl_freq + rem - i];
            ll right = (f[rem] * inv_f[rem - i]) % mod;
            // cout << i + sl_freq << "! * " << rem << "! / " << i << " = " << (left + right) << "\n";

            ans = (ans + left * right) % mod;
        }
        cout << (f[n] + mod - ans) % mod;
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precal();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}