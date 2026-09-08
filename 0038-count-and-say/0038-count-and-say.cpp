class Solution {
public:
    string countAndSay(int n) {

        string result = "1";

        for (int i = 2; i <= n; i++) {

            string next = "";

            int j = 0;

            while (j < result.length()) {

                char digit = result[j];

                int count = 0;

                // Count consecutive same digits
                while (j < result.length() &&
                       result[j] == digit) {
                    count++;
                    j++;
                }

                // Add count + digit
                next += to_string(count);
                next += digit;
            }

            result = next;
        }

        return result;
    }
};