// 20. Valid Parentheses
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto ch:s){
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{ // closing bracket
                if(!st.empty()){
                    if(st.top() == '(' && ch == ')'
                    || st.top() == '{' && ch == '}'
                    || st.top() == '[' && ch == ']'
                    ){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};