
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;  // adjust based on constraints

ll fact[MAXN + 1], invFact[MAXN + 1], inv[MAXN + 1];

// Fast exponentiation: a^b % MOD
ll modExp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverses
void init() {
    fact[0] = invFact[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // Fermat inverse of fact[MAXN]
    invFact[MAXN] = modExp(fact[MAXN], MOD - 2);

    // Compute inverse factorials using relation
    for (int i = MAXN - 1; i >= 1; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    // inv[i] = modular inverse of i
    for (int i = 1; i <= MAXN; i++) {
        inv[i] = invFact[i] * fact[i - 1] % MOD;
    }
}

// Compute nCr
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}


void solveTestcase() {
 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        if (fopen("in.txt", "r")) {
            freopen("in.txt", "r", stdin);
            freopen("out.txt", "w", stdout);
        }
    #endif

    init();

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Test Case : " << i << endl;
        solveTestcase();
        // cout << endl << endl;
    }

    return 0;
}
