class Solution {
public:
    bool check(int st, int end, string s){
        while(st<end){
            if(s[st]!=s[end]) return false;
            st++;
            end--;
        }
        return true;
    }
    int solve(int st, int end, string s,vector<vector<int>> &dp){
        if(st==end) return 0;
        if(check(st,end, s)==true) return dp[st][end] = 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int res = INT_MAX;
        for(int i =st;i<end;i++){
            int ans = 1 + solve(st,i,s,dp) + solve(i+1,end,s,dp);
            res = min(ans, res);
        }
        return dp[st][end] = res;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int st = n-2;st>=0;st--){
            for(int end = st+1;end<n;end++){
                if(check(st,end, s)==true){
                    dp[st][end] = 0;
                    continue;
                }
                // if(dp[st][end]!=-1) return dp[st][end];
                int res = INT_MAX;
                for(int i =st;i<end;i++){
                    int ans = 1 + dp[st][i] + dp[i+1][end];
                    res = min(ans, res);
                }
                dp[st][end] = res;
            }
        }
        return dp[0][n-1];
    }
};
