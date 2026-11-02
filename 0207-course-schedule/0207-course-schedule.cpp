class Solution {
public:

    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int vertex){
        if (visited[vertex] == 1) {
            return false;
        }
        if (visited[vertex] == 2) {
            return true;
        }
        
        visited[vertex] = 1;

        for (int next : adj[vertex]) {
            if (!dfs(adj, visited, next)) {
                return false;
            }
        }
        visited[vertex] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, -1);
        for (vector<int> pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        for (int i=0; i<adj.size(); i++){
            if (visited[i]==-1){
                if(!dfs(adj, visited, i)){
                    return false;
                }
            }
        }

        return true;
    }
};