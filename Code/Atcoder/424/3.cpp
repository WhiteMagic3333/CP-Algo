#include <string>
#include <unordered_map>
#include <queue>
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

vector<string> solution(vector<vector<string>> &laps) {
    vector<string> ans;
    unordered_map<string, queue<int>> time;
    for (auto &lap : laps) {
        for (auto &info : lap) {
            string name = "", t = "";
            for (int i = 0; i < info.length(); i++) {
                if (info[i] == ' ') {
                    i++;
                    while (i < info.length()) {
                        t += info[i];
                        i++;
                    }
                    break;
                }
                name += info[i];
            }
            time[name].push(stoi(t));
        }
    }
    unordered_map<string, int> last;
    for (auto [name, t] : time) { //
        last[name] = t.front(); //
    } //
    while (time.size()) {
        int mn = 0;
        for (auto [name, t] : time) {
            last[name] = min(last[name], t.front()); //
            mn = max(last[name], mn);
        }
        vector<string> cur;
        for (auto &[name, t] : time) {
            if (mn == last[name]) { //
                cur.push_back(name);
            } else {
                time[name].pop(); //
                if (time[name].size() == 0) {//
                    time.erase(name);//
                }//
            }
        }
        sort(cur.begin(), cur.end());
        for (auto &str : cur) {
            time.erase(str);
            ans.push_back(str);
        }
    }
    vector<string> cur;//
    for (auto [name, t] : last) {//
        cur.push_back(name);//
    }//
    sort(cur.begin(), cur.end());//
    for (auto i : cur) {//
        ans.push_back(i);//
    }//
    return ans;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<vector<string>> lap(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string name;
            int time;
            cin >> name >> time;
            lap[i].push_back(name + " " + to_string(time));
        }
    }
    solution(lap);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}