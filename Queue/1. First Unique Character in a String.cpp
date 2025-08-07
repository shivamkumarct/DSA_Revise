// 387 First Unique character in a string
// Time Complexity O(N)
// Space Complexity O(1) 

class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        int fre[26]={0};
        for(int i=0;i<n;i++)
            fre[s[i]-'a']++;

        for(int i=0;i<n;i++)
            if(fre[s[i]-'a']==1) return i;
        return -1;
    }
};