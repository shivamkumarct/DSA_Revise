// 51. N-Queen
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperDigonalCheck;
    unordered_map<int, bool> lowerDigonalCheck;

    void storeSol(vector<vector<char>>& board, int n, vector<vector<string>>& ans){
        vector<string> temp;
        for(int i=0; i<n; i++){
            string output = "";
            for(int j=0; j<n; j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>>& board, int n){
        if(rowCheck[row] ==  true)
            return false;
        if(upperDigonalCheck[n-1+col-row] == true)
            return false;
        if(lowerDigonalCheck[row+col] ==  true)
            return false;
        return true;
    }

    void solve(vector<vector<char>>& board, int col, int n, vector<vector<string>> & ans){
        // base case
        if(col >= n){
            storeSol(board, n, ans);
            return;
        }

        // solve 1 case rest recursion will solve
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                // Rakh do
                board[row][col]='Q';
                rowCheck[row] = true;
                upperDigonalCheck[n-1+col-row] = true;
                lowerDigonalCheck[row+col] = true;

                // Rc
                solve(board, col+1, n, ans);
                // backtracking
                board[row][col]='.';
                rowCheck[row] = false;
                upperDigonalCheck[n-1+col-row] = false;
                lowerDigonalCheck[row+col] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int col=0;

        solve(board, col, n, ans);
        return ans;
    }
};