// 300. Longest Increasing Subsequence
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int recursion(vector<int>& arr, int curr, int prev){
        // base case
        if(curr >= arr.size()) return 0;

        // include
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
            include = 1 + recursion(arr, curr+1, curr);
        
        // exclude
        int exclude = recursion(arr, curr+1, prev);

        int ans = max(include, exclude);
        return ans;
    }

    int memoization(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp){
        // base case
        if(curr >= arr.size()) return 0;

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        // include
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev])
            include = 1 + memoization(arr, curr+1, curr, dp);
        
        // exclude
        int exclude = memoization(arr, curr+1, prev, dp);

        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }

    int tabulation(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + dp[curr+1][curr+1];
                
                // exclude
                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int spaceOptimization(vector<int>& arr){
        int n = arr.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + nextRow[curr+1];
                
                // exclude
                int exclude = nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            // sift
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int optimal(vector<int>& arr){
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1; i<n; i++){
            if(arr[i] > ans.back()){
                // include
                ans.push_back(arr[i]);
            }
            else{
                // exclude
                // find index of just greather element
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // int curr = 0;
        // int prev = -1;
        // return recursion(nums, curr, prev);

        // int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return memoization(nums, curr, prev, dp);

        // return tabulation(nums);

        // return spaceOptimization(nums);

        return optimal(nums);
    }
};