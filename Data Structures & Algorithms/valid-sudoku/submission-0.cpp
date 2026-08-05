class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> squ(9);
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                char number=board[i][j];
                if(number=='.') {
                    continue;
                }
                int index=(i / 3) * 3 + j / 3;
                if(row[i].count(number)||col[j].count(number)||squ[index].count(number)) {
                    return false;
                }
                row[i].insert(number);
                col[j].insert(number);
                squ[index].insert(number);
            }
        }
        return true;
    }
};
