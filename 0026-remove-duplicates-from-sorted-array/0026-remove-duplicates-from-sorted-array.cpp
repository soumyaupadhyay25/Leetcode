class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        for(int i =0; i<n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] != nums[j]){
                    i++;
                     nums[i] = nums[j];
                }
               
                
            }
          return i+1;  
        }
      return 1;
    }
    
};