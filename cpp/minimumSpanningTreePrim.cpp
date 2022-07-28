# include <iostream>
# include <string>
# include <vector>

using namespace std;


class Solution {
public:
    int minCostConnectPoints(vector<vector<int> >& points) {
        int size = points.size();
        vector<bool> visited = vector<bool>(size, false);
        vector<int> minDist = vector<int>(size, INT_MAX);
        
        int numVisited = 0;
        minDist[0] = 0;

        int ret = 0;
        int minNext = 0;
        int findMinDist;
        int weight;
        
        while (numVisited < size) {
            
            findMinDist = INT_MAX;
            
            for (int i = 0; i < size ; i++) {
                if (visited[i] == false && minDist[i] < findMinDist) {
                    findMinDist = minDist[i];
                    minNext = i;
                }
            }
            
            ret += findMinDist;
            visited[minNext] = true;
            numVisited += 1;
            
            for (int i = 0 ; i < size ; i++) {
                weight = abs(points[i][0] - points[minNext][0]) + abs(points[i][1] - points[minNext][1]);
                if (minDist[i] > weight && visited[i] == false)
                    minDist[i] = weight;
            }
            
        }
        
        

        return ret;
    }
};
