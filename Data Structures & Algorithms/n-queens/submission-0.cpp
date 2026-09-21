class Solution {
    vector<vector<string>> res;
    vector<bool> col,posdig,negdig;
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        col.resize(n, false);
        posdig.resize(2 * n, false);
        negdig.resize(2 * n, false);
        backtrack(0,n,board);
        return res;
    }
    void backtrack(int row , int n,vector<string> &board)
    {
        if(row == n)
        {
            res.push_back(board);
            return;
        }
        for(int c = 0 ; c < n;c++)
       {
         if(col[c] || posdig[row + c] || negdig[row-c + n])
         {
            continue;
         }
         col[c] = true;
         posdig[row+c] = true;
         negdig[row-c+n] = true;
         board[row][c] = 'Q';

         backtrack(row+1 , n , board);
        
         col[c] = false;
         posdig[row+c] = false;
         negdig[row-c+n] = false;
         board[row][c] = '.';

         
     }
    }
};
