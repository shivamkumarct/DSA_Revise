// 907. Sum of Subarray minimums
// Time Complexity O(N)
// Space Complexity O(N) 

class Solution {
public:
    vector<int> getPrevSmall(vector<int>& arr, int n){
        vector<int> result(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getNextSmall(vector<int>& arr, int n){
        vector<int> result(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmall = getPrevSmall(arr, n);
        vector<int> nextSmall = getNextSmall(arr, n);

        long long ans =0;
        int M = 1e9+7;
        for(int i=0; i<n; i++){
            long long leftElement = i - prevSmall[i];
            long long rightElement = nextSmall[i] - i;

            // total subarray jinka minimum arr[i] hoga
            long long totalSubarray = leftElement * rightElement;

            long long sum = totalSubarray*arr[i];
            ans = (ans+sum)%M;
        }
        return ans;
    }
};