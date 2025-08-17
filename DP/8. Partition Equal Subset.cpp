// 416. Partition Equal subset
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    bool solveRecursion(int index, vector<int>& nums, int target){
        // base case
        if(index >= nums.size()) return false;

        if(target < 0) return false;

        if(target == 0) return true;

        bool include = solveRecursion(index+1, nums, target - nums[index]);
        bool exclude = solveRecursion(index+1, nums, target);

        return (include || exclude);
    }

    bool memoization(int index, vector<int>& nums, int target, vector<vector<int>>& dp){
        // base case
        if(index >= nums.size()) return false;

        if(target < 0) return false;

        if(target == 0) return true;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool include = memoization(index+1, nums, target - nums[index], dp);
        bool exclude = memoization(index+1, nums, target, dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool tabulation(int index, vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i=0; i<nums.size(); i++){
            dp[i][0] = 1;
        }

        for(int index=n-1; index>=0; index--){
            for(int t=1; t<=target; t++){
                bool include = 0; 
                if(t-nums[index]>=0)
                    include = dp[index+1][t-nums[index]];
                bool exclude = dp[index+1][t];

                dp[index][t] = (include || exclude);
            }
        }
        return dp[0][target];
    }

    bool spaceOptimization(vector<int>& nums, int target){
        int n = nums.size();

        vector<bool> curr(target+1, 0);
        vector<bool> next(target+1, 0);

        curr[0] = 1; 
        next[0] = 1;

        for(int index=n-1; index>=0; index--){
            for(int t=1; t<=target; t++){
                bool include = 0; 
                if(t-nums[index]>=0)
                    include = next[t-nums[index]];
                bool exclude = next[t];

                curr[t] = (include || exclude);
            }
            next = curr;
        }
        return next[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%2) return false;
        int target = sum/2;

        // return solveRecursion(0, nums, target);

        // vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        // return memoization(0, nums, target, dp);

        // return tabulation(0, nums, target);


        return spaceOptimization(nums, target);
    }
};