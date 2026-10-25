class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool sortable = true;
        int breaks = 0;
        int zero;
        for (int i=0; i<n; i++){
            if (nums[i]>nums[(i+1)%n]){
                breaks++;
            }
            if (nums[i]==0){
                zero = i;
            }
        }
        if (n==1){
            return 0;
        }
        if (n==2){
            if (zero==0){
                return 0;
            }
            return 1;
        }
        //1 break -> increasing
        //n-1 breaks -> decreasing
        if (breaks == 1){
            return min(zero, n-zero+2);
        }
        else if (breaks == n-1){
            return min(n-zero, zero+2);
        }
        else{
            return -1;
        }
    }
};