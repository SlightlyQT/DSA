class Solution {
public:

    void check(vector<vector<char>>& board, vector<vector<int>>& visited, queue<pair<int, int>>& bfs){
        int i = bfs.front().first;
        int j = bfs.front().second;
        int m = board.size();
        int n = board[0].size();
        bfs.pop();
        //left;
        if (j>0 && visited[i][j-1]==-1 && board[i][j-1]=='O'){
            bfs.push({i, j-1});
            visited[i][j-1]=0;
        }
        //right
        if (j<n-1 && visited[i][j+1]==-1 && board[i][j+1]=='O'){
            bfs.push({i, j+1});
            visited[i][j+1]=0;
        }
        //up
        if (i>0 && visited[i-1][j]==-1 && board[i-1][j]=='O'){
            bfs.push({i-1, j});
            visited[i-1][j]=0;
        }
        //down
        if (i<m-1 && visited[i+1][j]==-1 && board[i+1][j]=='O'){
            bfs.push({i+1, j});
            visited[i+1][j]=0;
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> bfs;

        for (int i=0; i<m; i++){
            if (i==0 || i==m-1){
                for (int j=0; j<n; j++){
                    if (board[i][j]=='O' && visited[i][j]==-1){
                        bfs.push({i, j});
                        visited[i][j]=0;
                        while(bfs.size()){
                            check(board, visited, bfs);
                        }
                    }
                }
            }
            else{
                for (int j : {0, n-1}){
                    if (board[i][j]=='O' && visited[i][j]==-1){
                        bfs.push({i, j});
                        visited[i][j]=0;
                        while(bfs.size()){
                            check(board, visited, bfs);
                        }
                    }
                }
            }
        }

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]=='O' && visited[i][j]==-1){
                    board[i][j]='X';
                }
            }
        }
    }
};