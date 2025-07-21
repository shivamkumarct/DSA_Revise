// 767. Reorganize String 
// using simple count of frequncy in hash
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] ={0};
        for(int i=0; i<s.size(); i++){
            hash[s[i] - 'a']++;
        }

        // find the most frequent char
        char max_freq_char;
        int max_freq = INT_MIN;
        for(int i=0; i<26; i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                max_freq_char = i +'a';
            }
        }

        int index = 0;
        while(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index +=2;
        }

        if(max_freq != 0){
            return "";
        }

        hash[max_freq_char - 'a'] = 0;

        // lets place the rest of char
        for(int i=0; i<26; i++){
            while(hash[i] > 0){
                index = index >= s.size() ? 1:index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};

// using Priority Queue
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    typedef pair<int, char> P;
    
    string reorganizeString(string s) {
        int n = s.length();
        
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch-'a']++;

            if(count[ch-'a'] > (n+1)/2)
                return "";
        }
        
        priority_queue<P, vector<P>> maxHeap;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] > 0) {
                maxHeap.push({count[ch-'a'], ch});
            }
        }
        
        string result = "";
        while(maxHeap.size() >= 2) {
            auto P1 = maxHeap.top(); 
            maxHeap.pop();
            
            auto P2 = maxHeap.top();
            maxHeap.pop();
            
            result.push_back(P1.second);
            result.push_back(P2.second);
            
            P1.first--;
            P2.first--;
            
            if(P1.first > 0)
                maxHeap.push(P1);
            
            if(P2.first > 0)
                maxHeap.push(P2);
        }
        
        if(!maxHeap.empty())
            result.push_back(maxHeap.top().second);
        
        return result;
    }
};