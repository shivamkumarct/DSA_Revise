// 32. Longest Valid Parantheses
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans=0;
        st.push(-1);

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{  // ')'
                st.pop();
                if(st.empty()) // means invlid parantesis
                    st.push(i);
                else // calculate the length of the valid parantesis
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};