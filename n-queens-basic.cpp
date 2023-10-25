#include<bits/stdc++.h>
#define int int64_t
using namespace std;

void printBoard(int n,int board[20][20]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
bool canPlace(int n,int board[20][20],int x,int y){
    int i = x, j = y;
    while(i>=0){
        if(board[i][j]==1) return false;
        i--;
    }
    i=x,j=y;
    while(i>=0 && j>=0){
        if(board[i][j]==1) return false;
        i--;j--;
    }
    i=x,j=y;
    while(i>=0 && j<n){
        if(board[i][j]==1) return false;
        i--;j++;
    }
    return true;
}
bool solve(int n,int board[20][20],int i){
    if(i==n){
        printBoard(n,board);
        return true;
    }
    for(int j=0;j<n;j++){
        if(canPlace(n,board,i,j)){
            board[i][j]=1;
            bool success = solve(n,board,i+1);
            if(success) return true;
            board[i][j]=0;
        }
    }
    return false;
}

int32_t main(){
	freopen("cp.in", "r", stdin);
	freopen("cp.out", "w", stdout);
    int board[20][20] = {0};
    int n ;
    cin>>n;
    solve(n,board,0);
    return 0;

}
