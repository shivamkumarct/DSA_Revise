// 198. House Robber
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    // n-> represent index of curent house
    int recursion(vector<int>& nums, int n){
        // base case
        if(n < 0 ) return 0;
        if(n == 0) return nums[0];

        int include = recursion(nums, n-2) + nums[n];
        int exclude = recursion(nums, n-1) + 0;

        return max(include, exclude);
    }

    int memoization(vector<int>& nums, int n, vector<int>& dp){
        // base case
        if(n < 0 ) return 0;
        if(n == 0) return nums[0];

        if(dp[n] != -1) return dp[n];

        int include = memoization(nums, n-2, dp) + nums[n];
        int exclude = memoization(nums, n-1, dp) + 0;

        return dp[n] = max(include, exclude);
    }

    int tabulation(vector<int>& nums, int n){
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];

        for(int i=1; i<=n; i++){
            int temp = 0;
            if(i-2>=0)
                temp = dp[i-2];

            int include = temp + nums[i];
            int exclude = dp[i-1] + 0;

            dp[i] = max(include, exclude);
        }
        return dp[n];
    }

    int spaceOptimization(vector<int>& nums, int n){
        int prev1 = 0;
        int prev2 = nums[0];
        
        int curr = 0;
        for(int i=1; i<=n; i++){
            int temp = 0;
            if(i-2>=0)
                temp = prev1;

            int include = temp + nums[i];
            int exclude = prev2 + 0;

            curr = max(include, exclude);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        // return recursion(nums, n);

        // vector<int> dp(n+1, -1);
        // return memoization(nums, n, dp);

        // return tabulation(nums, n);

        return spaceOptimization(nums, n);
    }
};