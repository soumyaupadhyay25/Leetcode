class Solution {
public:
    int longestValidParentheses(string s) {
        int right = 0; int left = 0;
        int MaxLength = 0;

        //left to right Scan
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                left++;
            }else{
                right++;
            }

            if(left == right)
            {
                MaxLength = max(MaxLength,2*right);
            }

            //The moment rigth is more than left that means valid parenthesis sequence is broken so we reset the counter.
            if(right > left)
            {
                right = 0;
                left = 0;
            }
        }

        //Resetting the counter
        right = 0; 
        left = 0;

        //right to left scan
        for(int i = s.length(); i>= 0; i--)
        {
            if(s[i] == ')')
            {
                right++;
            }else
            {
                left++;
            }

            if(right == left)
            {
                MaxLength = max(MaxLength, 2* left);
            }
            //The moment left is more than right that means valid parenthesis sequence is broken so we reset the counter.
            if(left > right){
                left = 0; 
                right = 0;
            }
        }
        
        return MaxLength;
    }
};

//Dry run for better understanding :)