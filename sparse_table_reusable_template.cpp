#include<bits/stdc++.h>
using namespace std;
#define int int64_t

void runcase() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)  cin >> v[i];
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) { 
        lg[i] = lg[i / 2] + 1;
    }
    vector<vector<int>> st(lg[n] + 1, vector<int>(n));
    for (int i = 0; i < n; i++) 
        st[0][i] = v[i];
    for (int i = 1; i <= lg[n]; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int sum = 0;
        while (l <= r) {
            int j = lg[r - l + 1];
            sum += st[j][l];
            l += (1 << j);
        }
        cout << sum << endl;
    }    
}

int32_t main() {
    runcase();
}
