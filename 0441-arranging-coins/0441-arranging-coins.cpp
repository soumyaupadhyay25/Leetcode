class Solution {
public:
    int arrangeCoins(int n) {
        long long s = 0;
        long long e = n;
        long long mid, curr;
        
        while (s <= e) {
            mid = s + (e - s) / 2;
            
            // Sum of first mid rows: (mid * (mid + 1)) / 2
            curr = mid * (mid + 1) / 2;
            
            if (curr == n) {
                return mid;  // Exact match, mid is the answer
            }
            
            if (curr < n) {
                s = mid + 1;  // We need more rows
            } else {
                e = mid - 1;  // Too many coins, reduce rows
            }
        }
        
        return e;  // 'e' will be the largest value where curr <= n
    }
};
