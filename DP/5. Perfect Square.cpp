// 279. Perfect Square
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int solve(int n, vector<int>& dp){
        // base case
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        int i=1;
        int end = sqrt(n);
        while(i<=end){
            int perfectSquare = i*i;
            int numberOfPerfectSquare = 1 + solve(n - perfectSquare, dp);
            if(numberOfPerfectSquare < ans){
                ans = numberOfPerfectSquare;
            }
            ++i;
        }
        return dp[n] = ans;
    }

    int solveUsingBottomUp(int n, vector<int>& dp){
        // initial value
        dp[0] = 1;

        for(int i=1; i<=n; i++){
            int ans = INT_MAX;
            int start = 1;
            int end = sqrt(i);
            while(start<=end){
                int perfectSquare = start*start;
                int noOfPerfectSquare = 1 + dp[i-perfectSquare];
                if(noOfPerfectSquare < ans)
                    ans = noOfPerfectSquare;
                start++;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        // return solve(n, dp)-1;

        return solveUsingBottomUp(n, dp)-1;
    }
};