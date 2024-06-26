#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using int64 = long long;
const int N = 1e6 + 5;
vector<int> divi[N];
int spf[N];
int last[N];
struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    for (int64 i = 2; i < N; i++) {
        if (spf[i]) continue;
        for (int64 j = 2 * i; j < N; j += i) {
            if (!spf[j]) spf[j] = i;
            spf[j] = min((int)i, spf[j]);
        }
        spf[i] = i;
    }
    while (T--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        DSU dsu(2 * n - 1);
        int64 comp = 2 * n - 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                --comp;
                if (i) --comp;
                comp += n;
            }
        }
        vector<int> v;
        for (int i = 1; i < n; i++) {
            v.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            v.push_back(i);
        }
        for (int i = 0; i < v.size(); i++) {
            int y = v[i];
            int c = a[y];
            while (c > 1) {
                int cur = last[spf[c]];
                cur--;
                if (cur != -1) {
                    int dist = i - cur;
                    if (dist <= k) comp -= dsu.unite(cur, i);
                }
                last[spf[c]] = i + 1;
                c /= spf[c];
            }
        }
        cout << comp << '\n';
        for (int i = 0; i < v.size(); i++) {
            int y = v[i];
            int c = a[y];
            while (c > 1) {
                last[spf[c]] = 0;
                c /= spf[c];
            }
        }
    }
}
