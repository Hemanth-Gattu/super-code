class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>s;
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int box=(i/3)*3+j/3;
                if(board[i][j]=='.'){
                    continue;
                }
                if(s.find("b"+to_string(box)+board[i][j])==s.end()){
                     s.insert("b"+to_string(box)+board[i][j]);
                }
                else{
                    return 0;
                }
                if(s.find("r"+to_string(i)+board[i][j])==s.end()){
                    s.insert("r"+to_string(i)+board[i][j]);
                }
                else{
                    return 0;
                }
                if(s.find("c"+to_string(j)+board[i][j])==s.end()){
                    
                    s.insert("c"+to_string(j)+board[i][j]);
                }
                else{
                    
                   return 0; 
                }
              
            }
        }
        
        return 1;
    }
};
