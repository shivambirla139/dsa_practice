#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> arr, st;

void buildTree(int si, int ss, int se) {
    if (ss == se) {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    buildTree(2 * si, ss, mid);
    buildTree(2 * si + 1, mid + 1, se);
    st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe) {
    if (qs > se || qe < ss) return INF;
    if (ss >= qs && se <= qe) return st[si];
    int mid = (ss + se) / 2;
    int l = query(2 * si, ss, mid, qs, qe);
    int r = query(2 * si + 1, mid + 1, se, qs, qe);
    return min(l, r);
}

void update(int si, int ss, int se, int qi) {
    if (ss == se) {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    if (qi <= mid) update(2 * si, ss, mid, qi);
    else update(2 * si + 1, mid + 1, se, qi);
    st[si] = min(st[2 * si], st[2 * si + 1]);
}

int main() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    st.resize(4 * n);
    buildTree(1, 0, n - 1);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << "\n";
        } else {
            int idx, val;
            cin >> idx >> val;
            arr[idx] = val;
            update(1, 0, n - 1, idx);
        }
    }
}
