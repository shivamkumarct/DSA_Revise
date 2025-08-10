// 46. Permutation
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& ans){
        // base case;
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            solve(idx+1, nums, ans); 
            swap(nums[i], nums[idx]); // backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};