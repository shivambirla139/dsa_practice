#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int knapsack(int W,int n,vector<int> &w,vector<int> &v){
    if(n==-1 || W==0 ) return 0;
    if(w[n] <= W) return max(v[n]+knapsack(W-w[n],n-1,w,v),knapsack(W,n-1,w,v));
    return knapsack(W,n-1,w,v);
}
int32_t main(){
    vector<int> w = {1,2,4,5,2,4,2,5,6,8,3};
    vector<int> v = {2,4,5,2,4,3,5,3,2,4,2};
    cout<<knapsack(8,w.size()-1,w,v);
}
