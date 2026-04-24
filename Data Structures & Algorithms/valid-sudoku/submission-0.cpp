class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<char>>row, col;
        map<pair<int,int>, set<char>>square;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] =='.')continue;

                pair<int, int>p = {i/3, j/3};

                if(row[i].count(board[i][j]) ||
                col[j].count(board[i][j]) ||
                square[p].count(board[i][j])
                ){
                    return false;
                }

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                square[p].insert(board[i][j]);
            }
        }

        return true;
    }
};
