class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        // we want to take the max one in each round
        priority_queue<int> pq(nums.begin(), nums.end());
        // perform k rounds
        while (k--) {
            // get the max one
            int t = pq.top();
            // pop it out
            pq.pop();
            // add to answer
            ans += t;
            // add the ceil value
            // ceil(x / y) = (x + y - 1) / y
            // ceil(t / 3) = (t + 3 - 1) / 3 = (t + 2) / 3
            pq.push((t + 2) / 3);
        }
        return ans;
    }
};