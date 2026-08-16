class Solution {
public:
    string convert(string s, int numRows) {
        
        // If there is only one row, no zigzag conversion is needed
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = true;

        for (char c : s) {
            rows[currentRow] += c;

            // Change direction at the top and bottom
            if (currentRow == 0) {
                goingDown = true;
            }
            else if (currentRow == numRows - 1) {
                goingDown = false;
            }

            if (goingDown) {
                currentRow++;
            }
            else {
                currentRow--;
            }
        }

        // Combine all rows
        string result;

        for (string row : rows) {
            result += row;
        }

        return result;
    }
};