class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        dp[sr][sc]=color;
        int start_color=image[sr][sc];
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            
                image[val.first][val.second]=color;
                dp[val.first][val.second]=color;
                if(val.first-1>=0 && image[val.first-1][val.second]==start_color ){
                    if(dp[val.first-1][val.second]==-1){
                    q.push({val.first-1,val.second});
                    }
                    
                }
                if(val.second-1>=0&& image[val.first][val.second-1]==start_color){
                    if(dp[val.first][val.second-1]==-1){
                     q.push({val.first,val.second-1});   
                    }
                    
                }
                if(val.first+1<n&& image[val.first+1][val.second]==start_color){
                    if(dp[val.first+1][val.second]==-1){
                      q.push({val.first+1,val.second});  
                    }
                    
                }
                if(val.second+1<m&& image[val.first][val.second+1]==start_color){
                    if(dp[val.first][val.second+1]==-1){
                     q.push({val.first,val.second+1});   
                    }
                    
                }
            
        }
        return image;
        
    }
};
