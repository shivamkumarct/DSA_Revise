// 295. Find Median from Data Stream
// Time Complexity O(LogN)
// Space Complexity O(N)

class MedianFinder {
public:
    priority_queue<int> left; // maxHeap
    priority_queue<int, vector<int>, greater<int>> right; // minHeap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num < left.top()) 
            left.push(num);
        else 
            right.push(num);

        // maintain the size
        if(abs(int(left.size() - right.size())) > 1) {
            right.push(left.top());
            left.pop();
        }
        else if(left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size())
            return double(left.top() + right.top()) / 2;
        return left.top();
    }
};