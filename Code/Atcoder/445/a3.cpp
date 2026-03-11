typedef long long ll;

void solve() {
    int n = startTime.size();
    vector<array<ll, 2>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {startTime[i], endTime[i]};
    }

    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    ll ans = 0, cur_ppl = 0;
    for (auto cur : arr) {
       cur_ppl += cur[1];
       ans = max(ans, cur_ppl);
    }
    cout << ans;
}