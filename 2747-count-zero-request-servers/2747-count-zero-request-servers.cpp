
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int l = logs.size();
        int q = queries.size();

        // Sort logs by time
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // Store query time and original index
        vector<pair<int,int>> arr;

        for (int i = 0; i < q; i++) {
            arr.push_back({queries[i], i});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int,int> mp;
        vector<int> ans(q);

        int left = 0;
        int right = 0;

        for (int i = 0; i < q; i++) {
            int time = arr[i].first;
            int idx = arr[i].second;

            // Add logs that fall before or at query time
            while (right < l && logs[right][1] <= time) {
                mp[logs[right][0]]++;
                right++;
            }

            // Remove logs outside the time window
            while (left < right && logs[left][1] < time - x) {
                mp[logs[left][0]]--;

                if (mp[logs[left][0]] == 0) {
                    mp.erase(logs[left][0]);
                }

                left++;
            }

            // Count servers with no requests
            ans[idx] = n - mp.size();
        }

        return ans;
    }
};
