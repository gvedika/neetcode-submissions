class Solution {
public:

    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i >= nums.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int rob = nums[i] + solve(i + 2, nums, dp);

        int skip = solve(i + 1, nums, dp);

        dp[i] = max(rob, skip);

        return dp[i];
    }

    int helper(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);

        return solve(0, nums, dp);
    }

    int rob(vector<int>& nums)
    {
        if(nums.size() == 1)
            return nums[0];

        vector<int> first(nums.begin(), nums.end() - 1);

        vector<int> second(nums.begin() + 1, nums.end());

        int ans1 = helper(first);

        int ans2 = helper(second);

        return max(ans1, ans2);
    }
};