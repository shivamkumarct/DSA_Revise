// 5. Longest Palindromic Substring
// Brute Force
// Time Complexity O(N^3)
// Space Complexity O(1)

class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(s, i, j)){
                    string t = s.substr(i, j-i+1);
                    ans = t.size() > ans.size() ? t:ans;
                }
            }
        }
        return ans;
    }
};


// Using DP
// Time Complexity O(N^3)
// Space Complexity O(N^2)

class Solution {
public:
    int maxLen=1, start=0;
    bool solve(string& s, int i, int j, vector<vector<int>>& dp){
        // base case;
        if(i>=j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(s[i] == s[j])
            flag = solve(s, i+1, j-1, dp);
        
        if(flag){
            int curLen = j-i+1;
            if(curLen > maxLen){
                maxLen = curLen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                bool temp = solve(s, i, j, dp);
            }
        }
        return s.substr(start, maxLen);
    }
};