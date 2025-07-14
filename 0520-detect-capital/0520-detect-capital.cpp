class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;

        if (word.size() == 1)
            return true;  // One-letter word is always valid

        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i]))
                count++;
        }

        if (count == word.size()) // ALL uppercase
            return true;
        if (count == 0) // all lowercase
            return true;
        if (count == 1 && isupper(word[0])) // First capital only
            return true;

        return false;
    }
};
