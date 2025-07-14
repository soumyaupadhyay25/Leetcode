class Solution {
public:
    int addDigits(int num) {
        
      
    while (num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;   // add the last digit
            num /= 10;         // remove the last digit
        }
        num = sum;  // update num with the digit sum
    }
    return num;
}

    
};