// 70. Climbing Stairs
// Recursive
// Time Complexity O()
// Space Complexity O()

class Solution {
private:
    int count(int n){
        //base case
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        //Rc
        return count(n-1)+count(n-2);
    }
public:
    int climbStairs(int n) {
        return count(n);
    }
};


// Optimize
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        long long int prev1 = 1, prev2 = 1, temp;

        for(int i=0; i<n; i++){
            temp = prev1;
            prev1 += prev2;
            prev2 = temp;
        }
        return prev2;
    }
};
