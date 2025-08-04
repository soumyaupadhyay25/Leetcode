class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int maxLen = 0;
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(s, i, j) && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    result = s.substr(i, maxLen);
                }
            }
        }

        return result;
    }
};
