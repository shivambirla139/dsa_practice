#include<bits/stdc++.h>
#define int int64_t
using namespace std;


bool isSafe(int mat[9][9],int i,int j,int no){
    for(int k=0;k<9;k++){
        if(mat[i][k]==no || mat[k][j]==no) return false; 
    }
    int sx = i/3 , sy = j/3;
    sx*=3 , sy*=3;
    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(mat[x][y]==no) return false;
        }
    }
    return true;
}
void printSudoku(int mat[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
bool solve(int mat[9][9],int i,int j){
    if(i==9){
        printSudoku(mat);
        return true;
    }
    if(j==9) return solve(mat,i+1,0);
    if(mat[i][j]!=0) return solve(mat,i,j+1);

    for(int no=1;no<=9;no++){
        if(isSafe(mat,i,j,no)){
            mat[i][j]=no;
            bool success = solve(mat,i,j+1);
            if(success) return true;
        }
    }
    mat[i][j]=0;
    return false;
}
int32_t main(){
	freopen("cp.in", "r", stdin);
	freopen("cp.out", "w", stdout);
    int mat[9][9] = {};
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) cin>>mat[i][j];
    }
    if(!solve(mat,0,0)){
        cout<<"solution doesnt exist";
    }
}
