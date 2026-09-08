class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        // Numbers ending in 0 are not palindromes, except 0 itself
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse only half of the number
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // Even number of digits
        // Odd number of digits: ignore the middle digit
        return x == reversedHalf || x == reversedHalf / 10;
    }
};