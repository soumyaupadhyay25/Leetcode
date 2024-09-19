class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()- 1;
        
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(target ==  nums[mid]){
                return mid;
            }
            
            if(target <= nums[mid]){
                e = mid - 1;
            }
            
            else{
                s = mid + 1;
            }
            
        
        }
        
        return s;
    }
};