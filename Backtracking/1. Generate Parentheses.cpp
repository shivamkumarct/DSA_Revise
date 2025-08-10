// 22. Generate Parentheses
// Time Complexity O(2^N)
// Space Complexity O(N)

class Solution {
public:
    void solve(vector<string>& ans, int n, int open, int close, string output){
        // base case
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }

        // include open bracket
        if(open >0){
            output.push_back('(');
            solve(ans, n, open-1, close, output);
            //backtracking
            output.pop_back();
        }

        // include close bracket
        if(open<close){
            output.push_back(')');
            solve(ans, n, open, close-1, output);
            // backtracking
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open = n;
        int close = n;
        solve(ans, n, open, close, output);
        return ans;
    }
};