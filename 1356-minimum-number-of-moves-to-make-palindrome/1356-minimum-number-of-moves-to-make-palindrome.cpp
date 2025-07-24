class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        int count = 0;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }

            int k = r;
            while (k > l && s[k] != s[l]) {
                k--;
            }

            if (k == l) {
                // Unmatched char, bring to center
                swap(s[k], s[k + 1]);
                count++;
                continue;
            }

            while (k < r) {
                swap(s[k], s[k + 1]);
                k++;
                count++;
            }

            l++;
            r--;
        }

        return count;
    }
};
