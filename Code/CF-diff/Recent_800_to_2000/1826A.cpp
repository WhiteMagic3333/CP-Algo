#include <filesystem>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <unordered_set>
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
 
// void solve()
// {
//     //n people upto 100
//     //each says atleast l[i] liers amongst us

//     //after looking at the constraints brutforces was clear
//     //but i unnecessarily optimzed resulting wrong answer
//     //20 mins+
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     cin >> arr;
//     for (int liars = 0; liars <= n; liars++) {
//         //so l liars then n - l are speaking the truth and only last differs
//         int cnt_liars = 0;
//         for (auto i : arr) {
//             if (i > liars) {
//                 cnt_liars++;
//             }
//         }
//         if (cnt_liars == liars) {
//             cout << liars;
//             return;
//         }
//     }
//     cout << "-1";
// }

void solve()
{
    //n people upto 100
    //each says atleast l[i] liers amongst us
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
        int rem = n - i - 1;
        if (rem >= arr[i] && (i == n - 1 || rem < arr[i + 1])) {
            cout << rem;
            return;
        }
    }
    cout << "-1";
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