// 871. Minimum Number of Refueling Steps
// Time Complexity O(NLogN)
// Space Complexity O(N)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0, dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int, int>> pq; // {fuel, pos}

        while(true){
            while(i < stations.size() && stations[i][0] <= dist+fuel){
                // push station within the reach with my current fuel level from my current pos
                pq.push({stations[i][1], stations[i][0]});
                i++;
            }

            // travel with full fuel level
            dist += fuel;
            fuel = 0;

            // reached
            if(dist >= target) return stops;

            // no fuel station within reach
            if(pq.empty()) return -1;

            // refuel ans re-adjust dist & fuel based on the distance travel 
            auto& top = pq.top();
            fuel = (dist - top.second) + top.first; // curr se stop tak ka fuel substract and add additional fuel at that stop
            dist = top.second;
            pq.pop();
            stops++;
        }
        return stops;
    }
};