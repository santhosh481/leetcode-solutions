class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to safely handle INT_MIN
        long long a = dividend;
        long long b = divisor;

        a = llabs(a);
        b = llabs(b);

        long long quotient = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Find the largest doubled divisor
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        if (negative) {
            quotient = -quotient;
        }

        return (int)quotient;
    }
};