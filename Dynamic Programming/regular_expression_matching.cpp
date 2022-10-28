class Solution {
public:
    bool solve(int i , int j , string s, string p,vector<vector<int>> &dp){
        if(i<0 and j<0) return true;
        if(j<0 ) return false;
        if(i<0){
            if(p[j]=='*'){
                return solve(i,j-2,s,p,dp);
            }
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] or p[j]=='.'){
            return dp[i][j] = solve(i-1,j-1,s,p,dp);
        }
        else if(p[j]=='*'){
            dp[i][j] = solve(i,j-2,s,p,dp); //or solve(i,j-1,s,p,dp);
            if(s[i]==p[j-1] or p[j-1]=='.'){
                dp[i][j] = dp[i][j] or solve(i-1,j,s,p,dp);
            }    
            return dp[i][j];
        }
        return dp[i][j] = false;
        
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return solve(n-1,m-1,s,p,dp);
        
    }
};
