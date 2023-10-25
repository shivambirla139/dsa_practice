#include<bits/stdc++.h>
#define int int64_t
using namespace std;

void helper(char *input,char *output,int i,int j){
    if(input[i]=='\0'){
        output[j]='\0';
        if(output[0]=='\0') cout<<"EMPTY STRING "<<endl;
        else cout<<output<<endl;
        return ;
    }
    output[j]=input[i];
    helper(input,output,i+1,j+1);

    output[j]='\0';
    helper(input,output,i+1,j);
}

int32_t main(){
	freopen("cp.in", "r", stdin);
	freopen("cp.out", "w", stdout);
    char input[100];
    char output[100];
    cin>>input;
    helper(input,output,0,0);

}
