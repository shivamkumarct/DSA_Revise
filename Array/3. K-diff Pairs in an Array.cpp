// 532. K-diff Pairs in an Array
// using sorting and binary search
// Time Complexity O(NlogN)
// Space Complexity O(1)

class Solution {
public:
    int bs(vector<int>& nums, int s, int x){
        int e = nums.size()-1; 
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == x) return mid;
            else if(nums[mid] > x) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;

        for(int i=0; i<nums.size(); i++){
            if(bs(nums, i+1, nums[i]+k) != -1){
                ans.insert({nums[i], nums[i]+k});
            }
        }
        return ans.size();
    }
};


// using HashMap
// Time Complexity O(N)
// Space Complexity O(N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num:nums) freq[num]++;

        int ans = 0;
        for(auto it:freq) {
            if(k == 0) {
                if(it.second > 1) ans++;
            }
            else {
                if(freq.count(it.first + k)) ans++; 
            }
        }
        return ans;
    }
};