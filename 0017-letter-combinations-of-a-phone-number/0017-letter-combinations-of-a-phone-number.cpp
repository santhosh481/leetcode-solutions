class Solution {
public:
    vector<string> result;

    string letters[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string& current) {

        // All digits are processed
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        // Try every letter for this digit
        for (char c : letters[digit]) {

            current.push_back(c);

            backtrack(digits, index + 1, current);

            // Undo the choice
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }

        string current = "";

        backtrack(digits, 0, current);

        return result;
    }
};