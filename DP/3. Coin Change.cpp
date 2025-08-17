// 322. Coin Change
// Recursive + Memoization
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        // base case
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        //ans already exist
        if(dp[amount] != -1)
            return dp[amount];
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solve(coins, amount-coins[i], dp);
            if(ans != INT_MAX)
                mini = min(mini, 1+ans);
        }

        dp[amount] = mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};


// Bottom Up (Tab)
class Solution {
public:
    int solveTab(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                    int ans = dp[i - coins[j]];
                    dp[i] = min(dp[i], 1+ans);
                }
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {

        int ans = solveTab(coins, amount);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
