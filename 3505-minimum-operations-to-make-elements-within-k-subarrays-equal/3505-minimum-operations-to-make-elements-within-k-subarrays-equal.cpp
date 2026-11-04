class Solution {
public:

    vector<long long> cost;

    // Calculate costs of all windows of size x
    void calculateCost(vector<int>& nums, int x) {

        multiset<long long> left, right;

        long long sumLeft = 0, sumRight = 0;

        auto balance = [&]() {

            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());

                long long val = *it;
                left.erase(it);

                sumLeft -= val;
                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                auto it = right.begin();

                long long val = *it;
                right.erase(it);

                sumRight -= val;
                left.insert(val);
                sumLeft += val;
            }
        };

        auto add = [&](long long val) {

            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            }
            else {
                right.insert(val);
                sumRight += val;
            }

            balance();
        };

        auto remove = [&](long long val) {

            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            }
            else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }

            balance();
        };

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            add(nums[i]);

            if (i >= x) {
                remove(nums[i-x]);
            }

            if (i >= x-1) {

                long long median = *left.rbegin();

                long long operations =
                    median * (long long)left.size() - sumLeft
                    + sumRight - median * (long long)right.size();

                cost[i-x+1] = operations;
            }
        }
    }

    long long helper(vector<vector<long long>>& dp,
                     int k, int i, int n, int x) {

        if (k == 0) return 0;

        if (i > n-x) return LLONG_MAX / 2;

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        // Pick
        long long pick = cost[i] +
                         helper(dp, k-1, i+x, n, x);

        // Not pick
        long long notpick =
                         helper(dp, k, i+1, n, x);

        return dp[i][k] = min(pick, notpick);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        if (1LL * x * k > n) return -1;

        cost.resize(n-x+1);

        calculateCost(nums, x);

        vector<vector<long long>> dp(
            n, vector<long long>(k+1, -1)
        );

        return helper(dp, k, 0, n, x);
    }
};