class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> map;
        int i = 0, j = 0, len = 0, n = s.length();

        while (j < n) {
            if (!map.count(s[j])) {
                map.insert(s[j]);
                len = max(len, j - i + 1);
                j++;
            } else {
                map.erase(s[i]);
                i++;
            }
        }
        return len;
    }
};