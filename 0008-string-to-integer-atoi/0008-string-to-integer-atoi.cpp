class Solution {
public:
    // We use long for 'ans' to handle overflow checks comfortably
    int solve(string& s, int i, int sign, bool started) {
        // Base case: end of string
        if (i >= s.length()) return 0;

        // Skip leading spaces only if we haven't started parsing
        if (!started && s[i] == ' ') {
            return solve(s, i + 1, sign, false);
        }

        // Handle sign: only allowed exactly once before any digits
        if (!started && (s[i] == '+' || s[i] == '-')) {
            return solve(s, i + 1, (s[i] == '-' ? -1 : 1), true);
        }

        // If it's a digit, we start building the number
        if (isdigit(s[i])) {
            return collectDigits(s, i, sign, 0);
        }

        // If we hit anything else before digits, it's 0
        return 0;
    }

    int collectDigits(string& s, int i, int sign, long currentAns) {
        // Base case: not a digit or end of string
        if (i >= s.length() || !isdigit(s[i])) {
            return (int)(currentAns * sign);
        }

        // Calculate next value
        currentAns = currentAns * 10 + (s[i] - '0');

        // Immediate Overflow Check
        if (sign == 1 && currentAns > INT_MAX) return INT_MAX;
        if (sign == -1 && -currentAns < INT_MIN) return INT_MIN;

        return collectDigits(s, i + 1, sign, currentAns);
    }

    int myAtoi(string s) {
        return solve(s, 0, 1, false);
    }
};