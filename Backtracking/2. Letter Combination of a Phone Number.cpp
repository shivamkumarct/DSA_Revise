// 17. Letter combination of a phone number
// Time Complexity O(4^N)
// Space Complexity O(4^N)

class Solution {
public:
    vector<string> ans;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(string& digits, string& output, int index){
        if(index == digits.length()){
            ans.push_back(output);
            return;
        }

        int digit = digits[index] -'0';
        string value = mapping[digit];

        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1);
            // backtrack
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)  return ans;

        string output ="";
        solve(digits, output, 0);
        return ans;
    }
};