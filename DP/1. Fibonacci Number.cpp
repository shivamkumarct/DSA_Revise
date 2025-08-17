// 509. Fibonacci Number
// Recursive + memoization
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int solve(int n, vector<int>& dp){
        //base case 
        if(n <= 1)
            return n;

        // step 3
        if(dp[n] != -1) return dp[n];

        // step 2
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        //step 1
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};

// Bottom up
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++)
            dp[i] =  dp[i-1] + dp[i-2];
            
        return dp[n];
    }
};


// space Optimization
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int prev1 = 0;
        int prev2 = 1;

        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};