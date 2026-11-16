
class Solution {
public:

    bool helper(vector<vector<int>>& graph, vector<int>& visited, queue<int>& bfs){
        while(bfs.size()){
            int node = bfs.front();
            bfs.pop();
        
            for (int x : graph[node]){
                if (visited[x] == 0){
                    visited[x] = -1 * visited[node];
                    bfs.push(x);
                }
                else if (visited[x] == visited[node]){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        queue<int> bfs;
        
        for (int i = 0; i < n; i++){
            if (visited[i] == 0){
                visited[i] = 1;
                bfs.push(i);
            }

            if (!helper(graph, visited, bfs)){
                return false; 
            }
        }

        return true;
    }
};
