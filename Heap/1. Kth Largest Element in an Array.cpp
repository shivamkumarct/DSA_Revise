// 215. Kth largest Element in an Array
// Time Complexity O(N)
// Space Complexity O(K)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(int num:nums) {
            pq.push(num);
            while(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};