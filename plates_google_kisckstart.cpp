#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main(){
	freopen("cp.in", "r", stdin);
	freopen("cp.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,p;
        cin>>n>>k>>p;
        vector<vector<int>> arr(n+1,vector<int> (k+1,0));
        vector<vector<int>> pre(n+1,vector<int> (k+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){ 
                cin>>arr[i][j];
                pre[i][j] += pre[i][j-1]+arr[i][j];
            }
        }
        vector<vector<int>> dp(n+1,vector<int> (p+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=p;j++){ 
                for(int x=0;x<=min(j,k);x++){
                    dp[i][j]=max(dp[i][j],pre[i][x]+dp[i-1][j-x]);
                }
            }
        }
        cout<<dp[n][p]<<endl;
    }
}
