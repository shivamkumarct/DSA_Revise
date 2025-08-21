// 55. Jump Game
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > reach) return false;
            reach = max(reach, i+nums[i]);
        }
        return true;
    }
};