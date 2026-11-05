class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for (int x : arr1){
            int high = arr2.size()-1;
            int low = 0;
            int mindist = INT_MAX;
            while (low <= high){
                int mid = low + (high-low)/2;
                int dist = x-arr2[mid];
                if (dist == 0){
                    mindist = 0;
                    break;
                }
                else if (dist < 0){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }

                mindist = min(mindist, abs(dist));
            }
            if (mindist > d){
                count++;
            }
        }

        return count;
    }
};