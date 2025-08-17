// 983. Minimum cost for tickets
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i){
        // base case
        if(i >= days.size()) return 0;

        // solve for 1 case;
        // if one day pass taken
        int cost1 = costs[0] + solve(days, costs, i+1);

        // if 7 days pass taken;
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost2 = costs[1] + solve(days, costs, j);

        // if 30 days pass taken;
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost3 = costs[2] + solve(days, costs, j);

        return min(cost1, min(cost2, cost3));
    }

    int memoization(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        // base case
        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];
        // solve for 1 case;
        // if one day pass taken
        int cost1 = costs[0] + memoization(days, costs, i+1, dp);

        // if 7 days pass taken;
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost2 = costs[1] + memoization(days, costs, j, dp);

        // if 30 days pass taken;
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost3 = costs[2] + memoization(days, costs, j, dp);

        return dp[i] = min(cost1, min(cost2, cost3));
    }

    int bottomUP(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        dp[days.size()] = 0;

        for(int i=days.size()-1; i>=0; i--){
            // solve for 1 case;
            // if one day pass taken
            int cost1 = costs[0] + dp[i+1];

            // if 7 days pass taken;
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost2 = costs[1] + dp[j];

            // if 30 days pass taken;
            passEndDay = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost3 = costs[2] + dp[j];

            dp[i] = min(cost1, min(cost2, cost3));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, -1);
        // return solve(days, costs, 0);

        // return memoization(days, costs, 0, dp);

        return bottomUP(days, costs, 0, dp);
    }
};