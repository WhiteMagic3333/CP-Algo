#ifndef ONLINE_JUDGE
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
  string str;
  cin >> str;
  char url[1000] = "curl ";
  for (int i = 0; i < str.length(); i++) {
    url[i + 5] = str[i];
  }
  size_t size;
  FILE *remote_file = popen(url, "r");
  char buf[100000];
  do {
    size = fread(buf, sizeof(char), 100000, remote_file);
    // fwrite(buf, sizeof(char), size, stdout);
  } while (100000 == size);
  string html;
  for (int i = 0; i < 100000; i++)
    html.push_back(buf[i]);
  for (int i = 10; i < html.length(); i++) {
    string cur = html.substr(i - 10, 10);
    if (cur == "Difficulty") {
      cur = html.substr(i + 9, 4);
      cout << cur;
      break;
    }
  }

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}