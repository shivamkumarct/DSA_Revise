// 1655. Distribute Repeating integer
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    bool solve(vector<int>& count, vector<int>& quantity, int ithCustomer){
        // base case
        if(ithCustomer == quantity.size()) return true;

        for(int i=0; i<count.size(); i++){
            if(count[i] >= quantity[ithCustomer]){
                count[i] -= quantity[ithCustomer];
                if(solve(count, quantity, ithCustomer + 1)) return true;

                count[i] += quantity[ithCustomer]; // backtrack
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> countMap;
        for(auto num:nums){
            countMap[num]++;
        }
        vector<int> count;
        for(auto it:countMap){
            count.push_back(it.second);
        }
        sort(quantity.rbegin(), quantity.rend()); // sort in decending order
        return solve(count, quantity, 0);
    }
};