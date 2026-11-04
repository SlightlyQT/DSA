class Solution {
public:

    bool cycle(vector<vector<int>>& coursemap, vector<int>& visited, int node){
        if (visited[node]==1){
            return true;
        }
        if (visited[node]==2){
            return false;
        }
        visited[node] = 1;
        for (int x : coursemap[node]){
            if (cycle(coursemap, visited, x)){
                return true;
            }
        }
        visited[node]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> coursemap(numCourses);
        vector<int> visited(numCourses, 0);
        for (auto x : prerequisites){
            coursemap[x[0]].push_back(x[1]);
        }

        for (int i=0; i<numCourses; i++){
            if (cycle(coursemap, visited, i)){
                return false;
            }
        }
        return true;
    }
};