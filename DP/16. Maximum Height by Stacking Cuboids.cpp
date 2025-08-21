// 1691. Maximum Height by Stacking Cuboids
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int spaceOptimization(vector<vector<int>>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || (arr[curr][0] >= arr[prev][0] && arr[curr][1] >= arr[prev][1] && arr[curr][2] >= arr[prev][2]))
                    include = arr[curr][2] + nextRow[curr + 1];

                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //sort every array
        for(auto &a: cuboids) {
            sort(a.begin(), a.end());
        }

        //sort the 2D array
        sort(cuboids.begin(), cuboids.end());

        //apply lis logic
        int ans = spaceOptimization(cuboids);
        return ans;
    }
};