class Solution {
public:

    void check(vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<int, int>>&bfs){
        int i = bfs.front().first;
        int j = bfs.front().second;
        int m = grid.size();
        int n = grid[0].size();
        bfs.pop();

        //left
        if (j>0 && grid[i][j-1]==0 && visited[i][j-1]==-1){
            bfs.push({i, j-1});
            visited[i][j-1]++;
        }
        //right
        if (j<n-1 && grid[i][j+1]==0 && visited[i][j+1]==-1){
            bfs.push({i, j+1});
            visited[i][j+1]++;
        }
        //up
        if (i>0 && grid[i-1][j]==0 && visited[i-1][j]==-1){
            bfs.push({i-1, j});
            visited[i-1][j]++;
        }
        //down
        if (i<m-1 && grid[i+1][j]==0 && visited[i+1][j]==-1){
            bfs.push({i+1, j});
            visited[i+1][j]++;
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m<3 || n<3){
            return 0;
        }
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> bfs;

        for (int i=0; i<m; i++){
            if (i==0 || i==m-1){
                for (int j=0; j<n; j++){
                    if (grid[i][j]==0 && visited[i][j]==-1){
                        bfs.push({i, j});
                        visited[i][j]++;
                    }
                    while (bfs.size()){
                        check(grid, visited, bfs);
                    }
                }
            }
            else{
                for (int j : {0, n-1}){
                    if (grid[i][j]==0 && visited[i][j]==-1){
                        bfs.push({i, j});
                        visited[i][j]++;
                    }
                    while (bfs.size()){
                        check(grid, visited, bfs);
                    }
                }
            }
        }

        int count = 0;
        for (int i=1; i<m-1; i++){
            for (int j=1; j<n-1; j++){
                if (grid[i][j]==0 && visited[i][j]==-1){
                    bfs.push({i, j});
                    visited[i][j]++;

                    while (bfs.size()){
                        check(grid, visited, bfs);
                    }
                    count++;
                }    
            }
        }
        return count;
    }
};