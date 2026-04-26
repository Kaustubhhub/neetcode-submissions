class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = piles[0];
        int minHr = INT_MAX;
        for (int pile : piles) {
            high = max(high, pile);
        }
        int low = 1;
        while (high >= low) {
            int mid = low + (high-low)/2;
            int currTime = 0;

            for(int pile : piles){
                currTime += (pile + mid -1)/mid;
            }

            if(currTime <= h){
                minHr = min(minHr, mid);
                high = mid-1;

            }else{
                low = mid+1;
            } 
        }
        return minHr;
    }
};
