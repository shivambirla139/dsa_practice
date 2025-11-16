class Solution {
public:
    long long dp[16][2][2];
    long long solve(string s , int index , bool started ,bool last){
        if(index == s.size()) return started;
        if(dp[index][started][last] != -1 ){
            return dp[index][started][last];
        }
        int till = last ? s[index] - '0' : 9;
        long long ret  = 0;
        for(int i = 0; i <= till ; i++){
            if(i == 0){
                if(!started)
                    ret += solve(s,index+1,started,(last && i == till));
            }
            else 
                ret += solve(s, index+1, true, (last && i == till));
        }
        return dp[index][started][last] =  ret ;
    }
    long long countDistinct(long long n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,false,true);
    }
};©leetcode
