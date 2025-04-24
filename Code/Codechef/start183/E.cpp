#include <iostream>
using namespace std;

typedef long long ll;

ll computeSumW(ll N, ll M) {
    ll totalEdges = N * (N - 1) / 2;
    ll zeroEdges = totalEdges - M;
    ll need = N - 1;

    ll minW = max(0LL, need - zeroEdges);
    ll maxW = min(need, M);

    if (minW > maxW) return 0;

    ll count = maxW - minW + 1;
    ll sum = (minW + maxW) * count / 2;
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll N, M;
        cin >> N >> M;
        cout << computeSumW(N, M) << "\n";
    }

    return 0;
}
