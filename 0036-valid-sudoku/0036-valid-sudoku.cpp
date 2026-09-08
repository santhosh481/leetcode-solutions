class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                char num = board[i][j];

                // Find the 3x3 box
                int box = (i / 3) * 3 + (j / 3);

                // Duplicate in row
                if (rows[i].count(num)) {
                    return false;
                }

                // Duplicate in column
                if (columns[j].count(num)) {
                    return false;
                }

                // Duplicate in box
                if (boxes[box].count(num)) {
                    return false;
                }

                // Add number
                rows[i].insert(num);
                columns[j].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};