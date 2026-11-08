class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<int> rows(m, 0);
        vector<int> columns(n, 0);
        //rows
        for (int i=0; i<m; i++){
            for (int x : grid[i]){
                if (x == 1){
                    rows[i]++;
                }
            }
        }
        //columns
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[j][i]==1){
                    columns[i]++;
                }
            }
        }
        //check
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1 &&
                    (rows[i] > 1 || columns[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};