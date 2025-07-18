class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int n = nums.size() / 3;
        vector<long long> diff(n + 1, 0);

        // Max heap for left part
        priority_queue<int> pqL;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            pqL.push(nums[i]);
            sum += nums[i];
        }

        for (int i = n; i <= 2 * n; i++) {
            diff[i - n] = sum;

            int x = nums[i];
            if (x >= pqL.top()) continue;
            sum += x - pqL.top();
            pqL.pop();
            pqL.push(x);
        }

        // Min heap for right part
        priority_queue<int, vector<int>, greater<int>> pqR;
        sum = 0;
        for (int i = 3 * n - 1; i >= 2 * n; --i) {
            pqR.push(nums[i]);
            sum += nums[i];
        }

        for (int i = 2 * n - 1; i >= n - 1; i--) {
            diff[i - n + 1] -= sum;

            int x = nums[i];
            if (x <= pqR.top()) continue;
            sum += x - pqR.top();
            pqR.pop();
            pqR.push(x);
        }

        return *min_element(diff.begin(), diff.end());
    }
};

// Fast IO init
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
