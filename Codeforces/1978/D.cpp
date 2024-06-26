#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        int64 a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[0] += c;
        int mx = 0;//index
        for (int i = 0; i < n; i++) {
            if (a[i] > a[mx]) {
                mx = i;
            }
        }
        int64 sm = 0;
        for (int i = 0; i < n; i++) {
            if (i == mx) {
                cout << "0 ";
            }
            else if (i < mx) {
                int64 chk = a[i] + sm;//pref sum
                if (chk >= a[mx]) {
                    cout << i << " ";
                }
                else {
                    cout << i + 1 << " ";
                }
            }
            else {
                //i > mx
                cout << i << ' ';
            }
            sm += a[i];
        }
        cout << '\n';
    }
}
