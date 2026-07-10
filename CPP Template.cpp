#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define double long double 

const int mod = 1e9 + 7, inf = 1e18, maxn = 301;


void solveTestcase() {
    cout << "Shit works " << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        if (fopen("in.txt", "r")) {
            freopen("in.txt", "r", stdin);
            freopen("out.txt", "w", stdout);
        }
    #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Test Case : " << i << endl;
        auto start = chrono::high_resolution_clock::now();

        solveTestcase();

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        // cout << "Time taken: " << duration.count() << " milli Seconds\n";
        
        // cout << endl << endl;
    }
}
