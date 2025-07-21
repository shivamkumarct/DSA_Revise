// 1. Two Sum
// Brute Force
// Time Complexity O(N^2)
// Space Complexity O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target)
                    return {i, j};
            }
        }
        return {0,1};
    }
};

// Using map
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int remaining = target - nums[i];
            if(mp.find(remaining) != mp.end())
                return {mp[remaining], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};