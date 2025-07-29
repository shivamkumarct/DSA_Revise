// 49. Group Anagram
// using sort and hash
// Time Complexity O(Nklogk)
// Space Complexity O(Nk)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for(auto str:strs){
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};