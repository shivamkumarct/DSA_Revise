// 41. First Missing Positive
// Brute force
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(auto num: nums){
            if(num <= n) mp[num]++;    
        }

        for(int i=1; i<=n+1; i++){
            if(mp[i]==0) return i;
        }
        return -1;
    }
};


// Better
// Time Complexity O(NlogN)
// Space Complexity O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        for(int num:nums){
            if(num == ans) ans++;
            else if(num > ans) break;
        }
        return ans;
    }
};


// Optimal
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++)
            if(nums[i] < 0) nums[i] = 0;
        
        for(int i=0; i<n; i++){
            int val = abs(nums[i]);
            if(1 <= val && val <= n){
                if(nums[val - 1] > 0)
                    nums[val - 1] *= -1;
                else if(nums[val - 1] == 0)
                    nums[val -1] =  -1 * (n+1);
            }
        }
        for(int i=1; i<=n; i++)
            if(nums[i - 1] >= 0)
                return i;

        return n+1;
    }
};