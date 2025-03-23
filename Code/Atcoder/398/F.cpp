#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    long long hashBase = 29;
    long long modValue = 1e9 + 7;
    long long forwardHash = 0, reverseHash = 0, powerValue = 1;
    int palindromeEndIndex = -1;

    // Calculate rolling hashes and find the longest palindromic prefix
    for (int i = 0; i < s.length(); ++i) {
        char currentChar = s[i];

        // Update forward hash
        forwardHash =
            (forwardHash * hashBase + (currentChar - 'a' + 1)) % modValue;

        // Update reverse hash
        reverseHash =
            (reverseHash + (currentChar - 'a' + 1) * powerValue) % modValue;
        powerValue = (powerValue * hashBase) % modValue;

        // If forward and reverse hashes match, update palindrome end index
        if (forwardHash == reverseHash) {
            palindromeEndIndex = i;
        }
    }

    // Find the remaining suffix after the longest palindromic prefix
    string suffix = s.substr(palindromeEndIndex + 1);
    // Reverse the remaining suffix
    string reversedSuffix(suffix.rbegin(), suffix.rend());

    // Prepend the reversed suffix to the original string and return the
    // result
    cout << reversedSuffix + s;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}