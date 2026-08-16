class Solution {
public:
    pair<int, int> expand(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // Return valid palindrome boundaries
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int n = s.length();

        if (n <= 1) {
            return s;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++) {

            // Odd-length palindrome
            auto odd = expand(s, i, i);

            if (odd.second - odd.first > end - start) {
                start = odd.first;
                end = odd.second;
            }

            // Even-length palindrome
            auto even = expand(s, i, i + 1);

            if (even.second - even.first > end - start) {
                start = even.first;
                end = even.second;
            }
        }

        return s.substr(start, end - start + 1);
    }
};