class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_bananas = piles[0];
        for(int curr_banana : piles)max_bananas = max(curr_banana, max_bananas);

        int low = 1, high = max_bananas;
        int res = INT_MAX;
        while(low <= high){
            int curr = 0;
            int mid = (high+low)/2;
            for(int i=0; i<piles.size(); i++){
                curr += (piles[i] + mid - 1) / mid;
            }
            if(curr <= h){
                res = min(res, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
};
