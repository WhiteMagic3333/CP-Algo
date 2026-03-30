#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    int ans;
    
    for (int i = 1; i <= 2 * n - 2; i += 2) {
        cout << "? " << i << " " << i + 1 << endl;
        cin >> ans;
        if (ans == 1) {
            cout << "! " << i << '\n';
            return;
        }
    }
    
    int u1 = 2 * n - 1;
    int u2 = 2 * n;
    
    cout << "? " << u1 << " 1" << endl;
    cin >> ans;
    if (ans == 1) {
        cout << "! " << u1 << '\n';
        return;
    }
    
    cout << "? " << u1 << " 2" << endl;
    cin >> ans;
    if (ans == 1) {
        cout << "! " << u1 << '\n';
        return;
    }
    
    cout << "! " << u2 << '\n';
}
 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}