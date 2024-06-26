#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
template<class T>
class SegTree {
private:
    const T id = (int64) 0;
    vector<T> t;

public:
    int n;
    SegTree(int l) {
        t.resize(l * 2);
        n = l;
    }

    void build(vector<T> v) {
        for (int i = n; i < 2 * n; i++) {
            t[i] = v[i - n];
        }
        for (int i = n - 1; i >= 0; i--) {
            t[i] += t[(i << 1)] + t[(i << 1) ^ 1];
        }
    }

    void modify(int ind, T val) {
        for (t[ind += n] = val; ind > 1; ind >>= 1) {
            t[ind >> 1] = t[ind] + t[ind ^ 1];
        }
    }

    T _query(int l, int r) { //[l, r)
        T res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
    T query(int l, int r) { //[l, r]
        return _query(l, r + 1);
    }

};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        //we can do on original array and remove 2 sizes, and then bruteforce the ends i think
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
            b[i] = t[i] - '0';
        }
        for (int i = 0; i + 2 < n; i++) {
            if (a[i] == 0 && a[i + 2] == 0) {
                b[i + 1] = 1;
            }
        }
        SegTree<int> st(n);
        for (int i = 0; i + 2 < n; i++) {
            if (b[i] == 1 && b[i + 2] == 1) {
                a[i + 1] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            st.modify(i, a[i]);
        }
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            if (l + 2 >= r - 2) {
                //brute force
                string ss = "";
                string tt = "";
                for (int i = l; i <= r; i++) {
                    ss += s[i];
                    tt += t[i];
                }
                int sz = r - l + 1;
                int aa[sz]; int bb[sz];
                for (int i = 0; i < sz; i++) {
                    aa[i] = ss[i] - '0';
                    bb[i] = tt[i] - '0';
                }
                for (int i = 0; i + 2 < sz; i++) {
                    if (aa[i] == 0 && aa[i + 2] == 0) {
                        bb[i + 1] = 1;
                    }
                }
                for (int i = 0; i + 2 < sz; i++) {
                    if (bb[i] == 1 && bb[i + 2] == 1) {
                        aa[i + 1] = 1;
                    }
                }
                int ans = accumulate(aa, aa + sz, 0);
                cout << ans << '\n';
            }
            else {
                //query + bruteforce
                int ans = st.query(l + 2, r - 2);
                int f = 0;
                if (s[l + 1] == '0' && s[l + 3] == '0') {
                    f = 1;
                }
                if (t[l + 2] == '1') f = 1;
                int ff = 0;
                if (t[l] == '1' && f) {
                    ff = 1;
                }
                if (s[l + 1] == '1') ff = 1;
                ans += ff;
                if (s[l] == '1') ans++;
                if (s[r] == '1') ans++;
                f = 0;
                if (s[r - 1] == '0' && s[r - 3] == '0') {
                    f = 1;
                }
                if (t[r - 2] == '1') f = 1;
                ff = 0;
                if (t[r] == '1' && f) {
                    ff = 1;
                }
                if (s[r - 1] == '1') ff = 1;
                ans += ff;
                cout << ans << '\n';
            }
        }
    }
}
