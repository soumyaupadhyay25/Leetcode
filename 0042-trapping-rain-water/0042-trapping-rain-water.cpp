#include <vector>
#include <numeric> // For accumulate
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        vector<int> heightcopy = height;

        int i = 0, j = height.size() - 1, Level = 0;

        while (i < j) {
            if (heightcopy[i] < Level) { heightcopy[i] = Level; i++; }
            else if (heightcopy[i] == Level) i++;
            else if (heightcopy[j] < Level) { heightcopy[j] = Level; j--; }
            else if (heightcopy[j] == Level) j--;
            else if (heightcopy[i] > Level && heightcopy[j] > Level) {
                Level++;
            }
        }

        int sumTotal = accumulate(heightcopy.begin(), heightcopy.end(), 0);  
        int sumHeight = accumulate(height.begin(), height.end(), 0);
        
        return sumTotal - sumHeight;
    }
};
