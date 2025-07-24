class Solution {
public:
    string truncateSentence(string s, int k) {
        string current = "";
        int wordcount = 0;

        for(int i = 0; i <s.length(); i++){
            if(s[i] != ' '){
                current += s[i];
            }
            else{
                wordcount++;
                if(wordcount == k){
                    break;
                }
                current += ' ';
            }
        }
        return current;
        
    }
};