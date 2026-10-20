class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k=1; k<=n; k++){
            if (n%k!=0){
                continue;
            }
            int i = 0;
            int prev = INT_MIN;
            bool skip = false;
            while (i<n){
                int peaks = 0;
                int maxx = INT_MIN;
                int minn = INT_MAX;
                for (int j=0; j<k; j++){
                    if (nums[i+j]>nums[i+((j+1)%k)]){
                        peaks++;
                    }
                    minn = min(minn, nums[i+j]);
                    maxx = max(maxx, nums[i+j]);
                }
                if (peaks>1 || minn<prev){
                    skip = true;
                    break;
                }
                prev = maxx;
                i += k;
            }
            if (!skip){
                ans += k;
            }
        }

        return ans;
    }
};