
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int slope = 0;
        int best = 1;
        int count = 1;

        for (int i=1; i<nums.size(); i++){
            int curr = 0;

            if (nums[i] > nums[i-1]){
                curr = 1;
            }
            else if (nums[i] < nums[i-1]){
                curr = -1;
            }

            if (curr == 0){
                best = max(best, count);
                count = 1;
                slope = 0;
            }
            else if (slope == 0 || curr == slope){
                count++;
                slope = curr;
            }
            else{
                best = max(best, count);
                slope = curr;
                count = 2;
            }
        }

        best = max(best, count);
        return best;
    }
};
