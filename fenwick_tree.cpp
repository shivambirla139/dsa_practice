#include<bits/stdc++.h>
using namespace std;
struct FenwickTree {
    int N;
    vector<int> bit;
    FenwickTree(int n) {
        this->N = n;
        bit.resize(N + 1, 0);
    }
    void update(int i, int val) {
        for (; i <= N; i += (i & (-i))) {
            bit[i] += val;
        }
    }
    int sum(int i) {
        int sum = 0;
        for (; i > 0; i -= (i & (-i))) {
            sum += bit[i];
        }
        return sum;
    }
};

int main(){
	
}
