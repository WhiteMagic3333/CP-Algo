#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, p;
        cin >> n >> p;
        vector<int> x(n);
        for (int j = 0; j < n; j++) {
            cin >> x[j];
        }

        set<int> seen;
        int operations = 0;

        for (int j = 0; j < n; j++) {
            if (seen.find(x[j]) == seen.end()) {
                seen.insert(x[j]);
                operations++;
            }
        }

        if (seen.size() < p) {
            operations += p - seen.size();
        }
        cout << operations << endl;
    }

    return 0;
}