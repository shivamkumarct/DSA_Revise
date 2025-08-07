// 225 Implement stack using queue

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int pop = q.front();
        q.pop();
        return pop;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// using dequeue we can perform all operation in O(1) time