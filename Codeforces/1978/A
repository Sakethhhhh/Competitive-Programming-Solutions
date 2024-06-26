#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ans = a[n - 1];
        int mx = 0;
        for (int i = 0; i < n - 1; i++) {
            mx = max(mx, a[i]);
        }
        cout << ans + mx << '\n';
    }
}
