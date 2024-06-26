#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64 n;
        int64 k;
        cin >> n >> k;
        int64 k1 = k;
        if (k % 2) {
            cout << "NO\n";
            continue;
        }
        int64 mx = 0;
        for (int64 i = 0; i < n; i++) {
            mx += abs(i + 1 - (n - i));
        }
        if (k > mx) {
            cout << "NO\n";
            continue;
        }
        vector<int64> mv = {};
        // for(int i = )
        cout << "YES\n";
        for (int64 i = 2 * (n - 1); i > 0; i -= 4) {
            if (k >= i) {
                k -= i;
                mv.push_back(i);
            }
        }
        if (k) mv.push_back(k);
        int used[n] = {0};
        vector<int64> p(n);
        iota(p.begin(), p.end(), 1);
        reverse(mv.begin(), mv.end());
        for (int64 i = 0; i < n; i++) {
            if (mv.empty()) break;
            if (used[i]) continue;
            int x = mv.back();
            int need = i + (x / 2);
            if (used[need]) continue;
            used[need] = used[i] = 1;
            swap(p[need], p[i]);
            mv.pop_back();
        }
        int64 sm = 0;
        for (int i = 0; i < n; i++) {
            sm += abs(p[i] - (i + 1));
        }
        assert(sm == k1);
        for (auto x : p) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
