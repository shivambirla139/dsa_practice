struct LazySegTree {
    int n;
    vector<long long> tree, lazy;

    LazySegTree(int sz) {
        n = sz;
        tree.assign(4 * n + 4, 0);
        lazy.assign(4 * n + 4, 0);
    }

    void build(int node, int l, int r, vector<int> &a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;

        tree[node] += (r - l + 1) * lazy[node];

        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);

        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if (r < ql || l > qr) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return query(2 * node, l, mid, ql, qr)
             + query(2 * node + 1, mid + 1, r, ql, qr);
    }

    // wrappers
    void build(vector<int> &a) {
        build(1, 0, n - 1, a);
    }

    void update(int l, int r, long long val) {
        update(1, 0, n - 1, l, r, val);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};