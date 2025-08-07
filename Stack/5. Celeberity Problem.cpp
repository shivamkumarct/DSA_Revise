// 394. Decode String
// this is GFG question giving some error 


class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        
        stack<int> st;
        for(int i = 0; i < n; i++) 
            st.push(i);
            
        while(st.size() > 1) {
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            
            if(mat[a][b] == 1) { // means a know b
                st.push(b);
            }
            else if(mat[b][a] == 1) { // means b know a
                st.push(a);
            }
        }
        
        int a = st.top();
        st.pop();
        
        // verify
        // celibrity knows no one 
        for(int i = 0; i < n; i++) {
            if(mat[a][i] == 1 && a != i) {
                return -1;
            }
                
        }
        
        // everyone knows celebrity
        for(int i = 0; i < n; i++) {
            if(mat[i][a] == 0 && i != a) {
                return -1;
            }
        }
        
        return a;
    }
};