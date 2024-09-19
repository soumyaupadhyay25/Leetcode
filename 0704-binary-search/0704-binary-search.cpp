class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mid = 0;
       
        while(s<=e){
            mid = s + (e-s)/2;
            if(target == nums[mid]){
                return mid;
            }
            
            if(target > nums[mid]){
                s = mid + 1;
                
            }
            
            else{
                e = mid -1;
            }
            
            int mid = s + (e - s)/2;
        }
         return -1;
    }
   
};