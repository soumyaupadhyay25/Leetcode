class Solution {
public:
    string reverseVowels(string s) {
        int left =0;
        int right = s.length()-1;
        string vowel = "aeiouAEIOU";

        while(left < right){
            if (vowel.contains(s[right]) && vowel.contains(s[left])){
                swap(s[right], s[left]);
                left++;
                right--;
            }
            else{
                if(!vowel.contains(s[left]))
                left++;

                if(!vowel.contains(s[right]))
                right--;

            }



        }
        return s;
        
    }
};