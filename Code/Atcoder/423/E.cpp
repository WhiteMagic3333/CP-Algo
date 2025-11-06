#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;

        ll result = 0;
        for (ll j = L; j <= R; ++j) {
            ll left = j - L + 1;
            ll right = R - j + 1;
            result += (ll)A[j] * left * right;
        }

        cout << result << '\n';
    }

    return 0;
}
