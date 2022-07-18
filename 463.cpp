class Solution {
public:
    int islandPerimeterMY(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> cur {-1, -1};
        int ret = 0;
        queue<vector<int>> q;
        for (int i = 0; i < row ; i++) {
            for (int j = 0; j < col ; j++) {
                if (grid[i][j] == 1) {
                    cur[0] = i, cur[1] = j;
                    break;
                }
            }
            if (cur[0] != -1)
                break;
        }
        
        
        q.push(cur);
        int edge = 0, x, y;
        while (!q.empty()) {
            edge = 0;
            cur = q.front();
            q.pop();
            if (grid[cur[0]][cur[1]] == 2)
                continue;
            grid[cur[0]][cur[1]] = 2;
            
            x = cur[0] - 1, y = cur[1];
            if (x >= 0){
                if (grid[x][y] == 1)
                    q.push(vector<int>{x, y});
                else if (grid[x][y] == 0)
                    edge++;
            }else
                edge++;
            
            x = cur[0] + 1, y = cur[1];
            if (x < row) {
                if (grid[x][y] == 1)
                    q.push(vector<int>{x, y});
                else if (grid[x][y] == 0)
                    edge++;
            } else
                edge++;
            
            x = cur[0], y = cur[1] + 1;
            if (y < col) {
                if (grid[x][y] == 1)
                    q.push(vector<int>{x, y});
                else if (grid[x][y] == 0)
                    edge++;
            } else
                edge++;
                
            x = cur[0], y = cur[1] - 1;
            if (y >= 0) {
                if (grid[x][y] == 1)
                    q.push(vector<int>{x, y});
                else if (grid[x][y] == 0)
                    edge++;
            } else
                edge++;
            
            ret += edge;
        }
        
        return ret;
    }
     
    // the fastest submission, very clever solution.
    int islandPerimeter(vector<vector<int>>& grid) {

        /*
        This question CAN be done with DFS or BFS and recursive relationship
        The iterative solution is easier both in logic and implementation

        */

        int count = 0;
        int i=0;
        while (i<grid.size()){
            int j=0;
            while (j<grid[0].size()){

                if (grid[i][j]==1){
                    count+=4;
                    if (i-1>=0 && grid[i-1][j]==1){
                        count-=2;
                        }
                    if (j-1>=0 && grid[i][j-1]==1){
                        count-=2;
                        }
                    }

                j+=1;
                }
            i+=1;
            }

        return count;

    }
};
