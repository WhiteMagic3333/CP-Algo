#include<bits/stdc++.h>

 
using namespace std;
 
#define ll long long
const ll INF = 1e18;
 
void solve() {
//on left (st, ed) <= (st[i], ed[i])
//on right (st, )

    int n;
    cin >> n;

    // store intervals
    vector<pair<int,int>> intervals(n);
    for (int i = 0; i < n; i++)
        cin >> intervals[i].first >> intervals[i].second;

    // sort by start time

    vector<int> pre(n, 0), suf(n, 0);

    /* ---------- PREFIX ---------- */
    // min heap storing end times
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> pq2; // max heap

    for (int i = 0; i < n; i++) {

        int start = intervals[i].first;
        int end = intervals[i].second;

        // remove finished intervals
        while (!pq.empty() && pq.top() < start)
            pq.pop();

        // remaining intervals overlap from left
        pre[i] = pq.size();

        // add current interval
        pq.push(end);
    }

    /* ---------- SUFFIX ---------- */
    // heap storing start times

    for (int i = n - 1; i >= 0; i--) {

        int start = intervals[i].first;
        int end   = intervals[i].second;

        // remove intervals that start after current end
        while (!pq2.empty() && pq2.top() > end)
            pq2.pop();

        // remaining overlap from right
        suf[i] = pq2.size();

        // add current start time
        pq2.push(start);
    }

    /* ---------- ANSWER ---------- */
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, pre[i] + suf[i] + 1);

    cout << ans;
}
 
int main() {
    solve();
    return 0;
}