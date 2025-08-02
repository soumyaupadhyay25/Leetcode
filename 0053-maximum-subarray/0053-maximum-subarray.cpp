class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arrSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            arrSum = max(nums[i], arrSum + nums[i]);
            maxSum = max(maxSum, arrSum);
        }

        return maxSum;
    }
};
