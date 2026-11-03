class Solution {
public:
    int minMoves(vector<int>& nums) {
        int high = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for (int x:nums){
            moves += (high-x);
        }

        return moves;
    }
};