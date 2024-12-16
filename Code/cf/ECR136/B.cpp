#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define ll long long int
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--)
  {
    ll n;
    cin >> n;
    ll d[n], a[n];
    for (ll i = 0; i < n; i++)
    {
      cin >> d[i];
    }
    a[0] = d[0];
    ll sum = a[0];
    bool flag = 1;
    for (ll i = 1; i < n; i++)
    {
      if (d[i] + a[i - 1] >= 0 && (a[i - 1] - d[i] >= 0) && (d[i] != 0))
      {
        flag = 0;
        break;
      }
      else
      {
        sum += d[i];
        a[i] = sum;
      }
    }
    if (flag == 0)
    {
      cout << -1 << endl;
    }
    else
    {
      for (ll i = 0; i < n; i++)
      {
        cout << a[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}