#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int N = 1000;
int a[N];
int n;
vector<vector<int>> dp(N,vector<int> (N,-1));
bool run(int i,int sum){
    if(dp[i][sum]!=-1) return dp[i][sum];
    if(i==n) return sum==0;
    bool ret = false;
    if(sum >= a[i]) ret |= run(i+1,sum-a[i]);
    ret |= run(i+1,sum);
    return dp[i][sum] = ret;
}


int32_t main(){
	freopen("cp.in", "r", stdin);
	freopen("cp.out", "w", stdout);
    int sum ;
    cin>>n>>sum;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<run(0,sum)<<endl;
}
