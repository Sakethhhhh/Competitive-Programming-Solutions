#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64 n, a, b;
        cin >> n >> a >> b;
        int64 k = min({n, b, {b - a + 1}});
        if (k < 0) k = 0;
        int64 ans = b * (b + 1) / 2 - (b - k) * (b - k + 1) / 2 + (n - k) * a;
        cout << ans << '\n';
    }
}
