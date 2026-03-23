class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the whole string
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0; // Where we are writing the "clean" string

        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // Add a space before the next word (but not the very first word)
                if (idx != 0) s[idx++] = ' ';

                // Find the end of the current word
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // Reverse the word back to its original order
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // Move start to the end of the word
                start = end;
            }
        }
        // Trim the original string to the new correct length
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};