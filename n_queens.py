class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        
        def backtrack(row, cols, diag, anti_diag, state):
            if row == n:
                board = []
                for r in state:
                    board.append("".join(r))
                ans.append(board)
                return
            
            for c in range(n):
                curr_diag = row - c
                curr_anti_diag = row + c
                
                if c in cols or curr_diag in diag or curr_anti_diag in anti_diag:
                    continue
                
                cols.add(c)
                diag.add(curr_diag)
                anti_diag.add(curr_anti_diag)
                state[row][c] = "Q"
                
                backtrack(row+1, cols, diag, anti_diag, state)
                
                cols.remove(c)
                diag.remove(curr_diag)
                anti_diag.remove(curr_anti_diag)
                state[row][c] = "."
        
        start_state = [["." for i in range(n)] for j in range(n)]
        backtrack(0, set(), set(), set(), start_state)
        return ans
