// 735 Asteroid Collison
// Time Complexity O(N)
// Space Complexity O(1) for storing ans 0(N)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // using vector as stack so we don't need to reverse the answer

        for(int i=0; i<asteroids.size(); i++){
            //collision hapen
            while(!st.empty() && asteroids[i] < 0 && st.back() > 0){
                int sum = st.back() + asteroids[i];
                if(sum < 0) 
                    st.pop_back();
                else if(sum > 0){
                    asteroids[i] = 0;
                }
                else{
                    asteroids[i] = 0;
                    st.pop_back();
                }
            }
            if(asteroids[i] != 0)
                st.push_back(asteroids[i]);
        }
        return st;
    }
};