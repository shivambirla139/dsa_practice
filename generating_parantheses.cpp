#include<bits/stdc++.h>
#define int int64_t
using namespace std;

void solve(string s,int i,int n,int open,int close){
    if(i==2*n){
        cout<<s<<endl;
        return ;
    }
    if(open < n) solve(s+'(',i+1,n,open+1,close);
    if(close<open) solve(s+')',i+1,n,open,close+1);
}
int32_t main(){
	freopen("cp.in", "r", stdin);
	freopen("cp.out", "w", stdout);
    string s;
    int n ;
    cin>>n;
    solve(s,0,n,0,0);
}
