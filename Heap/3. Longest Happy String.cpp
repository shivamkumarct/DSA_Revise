// 1405. Longest Happy String
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        
        string ans = "";
        while(!pq.empty()) {
            auto i = pq.top();
            pq.pop();

            int n = ans.length();
            if(n >= 2 && ans[n - 1] == i.second && ans[n - 2] == i.second) {
                if(pq.empty()) break;

                auto j = pq.top() ;
                pq.pop();

                ans += j.second;
                j.first--;
                if(j.first > 0) pq.push(j);
            }
            else {
                ans += i.second;
                i.first--;
            }
            if(i.first > 0) pq.push(i);
        }
        return ans;
    }
};