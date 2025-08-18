// 1962. Remove Stones to Minimize the Total
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(int num:piles) maxHeap.push(num);

        while(k--){
            int maxElement = maxHeap.top();
            maxHeap.pop();
            maxElement -= floor(maxElement/2);
            maxHeap.push(maxElement);
        }

        int sum=0;
        while(!maxHeap.empty()){
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};