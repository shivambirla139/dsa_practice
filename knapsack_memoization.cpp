#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int knapsack(int W,int n,vector<int> &w,vector<int> &v,vector<vector<int>> &dp){
    if(n== -1 || W== 0 ) return 0;
    if(dp[W][n] != -1) return dp[W][n];
    if(w[n] <= W) return dp[W][n]=max(v[n]+knapsack(W-w[n],n-1,w,v,dp),knapsack(W,n-1,w,v,dp));
    return dp[W][n]=knapsack(W,n-1,w,v,dp);
}
int32_t main(){
    int W = 8;
    vector<int> w = {1,2,4,5,2,4,2,5,6,8,3};
    vector<int> v = {2,4,5,2,4,3,5,3,2,4,2};
    vector<vector<int>> dp(W+1,vector<int> (w.size()+1,-1));
    cout<<knapsack(W,w.size()-1,w,v,dp);
}
