
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>> available;

        priority_queue<tuple<long long,int,int>, 
            vector<tuple<long long,int,int>>, 
            greater<tuple<long long,int,int>>> busy;

        vector<int> ans;
        
        // Initially all servers are available
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release all servers that have finished
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, idx] = busy.top();
                busy.pop();

                available.push({weight, idx});
            }

            // If no server is available, wait
            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, idx] = busy.top();
                    busy.pop();

                    available.push({weight, idx});
                }
            }

            // Assign the task to the best available server
            auto [weight, idx] = available.top();
            available.pop();

            ans.push_back(idx);

            // Mark the server as busy
            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};
