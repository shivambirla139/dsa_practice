#include <bits/stdc++.h>
using namespace std;

const int maxN = 100001;
int ar[maxN], st[4*maxN], lazy[4*maxN];

void build(int si, int ss, int se) {
    if (ss == se) { st[si] = ar[ss]; return; }
    int mid = (ss + se) / 2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);
    st[si] = st[2*si] + st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe) {
    if (lazy[si] != 0) {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);
        if (ss != se) {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return st[si];
    int mid = (ss + se) / 2;
    return query(2*si, ss, mid, qs, qe) + query(2*si+1, mid+1, se, qs, qe);
}

void update(int si, int ss, int se, int qs, int qe, int val) {
    if (lazy[si] != 0) {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);
        if (ss != se) {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        st[si] += val * (se - ss + 1);
        if (ss != se) {
            lazy[2*si] += val;
            lazy[2*si+1] += val;
        }
        return;
    }
    int mid = (ss + se) / 2;
    update(2*si, ss, mid, qs, qe, val);
    update(2*si+1, mid+1, se, qs, qe, val);
    st[si] = st[2*si] + st[2*si+1];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    build(1, 1, n);
    while (q--) {
        int code;
        cin >> code;
        if (code == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        } else {
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
    }
}
