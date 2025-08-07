// 394. Decode String
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch:s){
            if(ch == ']'){
                string stringToRepeate = "";
                while(!st.empty() && st.top() != "["){
                    stringToRepeate += st.top();
                    st.pop();
                }
                st.pop();
                string nums = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    nums += st.top();
                    st.pop();
                }
                reverse(nums.begin(), nums.end());
                
                int n = stoi(nums);

                string tempDecode = "";
                while(n--){
                    tempDecode += stringToRepeate;
                }
                st.push(tempDecode);
            }
            else{
                string temp(1, ch);
                st.push(temp);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};