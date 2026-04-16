struct SegmentTree {
    vector<int> st;
    vector<int>& v;
    int n;
    SegmentTree(vector<int>& v) : v(v) {
        this->n = v.size();
        st.resize(4 * n + 1, 0);
    }
    void buildTree(int si, int start, int end) {
        if (start == end) {
            st[si] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        buildTree(2 * si, start, mid);
        buildTree(2 * si + 1, mid + 1, end);
        st[si] = st[2 * si] + st[2 * si + 1];
    }
    void update(int si, int start, int end, int index) {
        if (start == end) {
            st[si] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid) update(2 * si, start, mid, index);
        else update(2 * si + 1, mid + 1, end, index);
        st[si] = st[2 * si] + st[2 * si + 1]; 
    }
    int query(int si, int start, int end, int queryStart, int queryEnd) {
        if (queryStart > end || queryEnd < start) {
            return 0;
        }
        if (queryStart <= start && queryEnd >= end) {
            return st[si];
        } 
        int mid = (start + end) / 2;
        int l = query(2 * si, start, mid, queryStart, queryEnd);
        int r = query(2 * si + 1, mid + 1, end, queryStart, queryEnd);
        return l + r;
    }
    void update(int index, int val) {
        v[index] = val; 
        update(1, 0, n - 1, index);
    }
    int query(int queryStart, int queryEnd) {
        return query(1, 0, n - 1, queryStart, queryEnd);
    }
    void buildTree() {
        buildTree(1, 0, n - 1);
    }
};
