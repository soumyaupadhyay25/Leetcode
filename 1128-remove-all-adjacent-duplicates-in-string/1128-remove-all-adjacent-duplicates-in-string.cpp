class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0; 
        for (int j = 0; j < s.length(); j++) {
            if (i > 0 && s[j] == s[i - 1]) {
                i--; 
            } else {
                s[i] = s[j];
                i++; 
            }
        }
        return s.substr(0, i);
    }
};
