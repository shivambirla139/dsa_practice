#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    const int INF = 1e9;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (d[i][j] == INF ? -1 : d[i][j]) << " ";
        cout << "\n";
    }
}