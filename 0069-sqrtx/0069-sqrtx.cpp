class Solution {
public:
    int binarySearch(int n) {
        if (n == 0 || n == 1) return n; // Edge cases for 0 and 1

        int s = 0;
        int e = n;
        long long int ans = -1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long int square = (long long int)mid * mid;
            
            if (square == n) {
                return mid;
            }
            
            if (square < n) {
                ans = mid;  
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        return ans; 
    }

    int mySqrt(int x) {
        return binarySearch(x);
    }
};
