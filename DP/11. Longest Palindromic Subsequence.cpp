// 516. Longest Palindromic Subsequence
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    // same as leetcode 1143 no.question
    int tabulation(string& a, string& b){
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + dp[i+1][j+1];
                else
                    ans = max(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int spaceOptimization(string& a, string& b){
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + next[j+1];
                else
                    ans = max(next[j], curr[j+1]);
                curr[j] = ans;
            }
            // sift
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(s.begin(), s.end());
        string b = s;

        return spaceOptimization(a, b);
    }
};