class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digitLastIndex(10);
        string numString(to_string(num));
        for (int i = 0; i < numString.size(); ++i) {
            digitLastIndex[numString[i] - '0'] = i;
        }

        for (int i = 0; i < numString.size(); ++i) {
            for (int digit = 9; digit > numString[i] - '0'; --digit) {
                if (digitLastIndex[digit] > i) {
                    swap(numString[i], numString[digitLastIndex[digit]]);

                    // we could only exchange once, so if we swap, we return
                    return stoi(numString);
                }
            }
        }

        // if the origin number is the best one, we will not swap any digits and return, so we just
        // return the origin number
        return num;
    }
};