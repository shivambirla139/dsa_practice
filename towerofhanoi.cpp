#include<bits/stdc++.h>
#define int int64_t
using namespace std;
char a='A',b='B',c='C';
void helper(int n,char a,char b,char c){
    if(n==0) return ;
    helper(n-1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    helper(n-1,b,a,c);
}

int32_t main(){
	freopen("cp.in", "r", stdin);
	freopen("cp.out", "w", stdout);
    int n ;
    cin>>n;
    helper(n,a,b,c);	

}
