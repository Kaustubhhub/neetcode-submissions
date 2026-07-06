class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0, high = heights.size()-1;
        int ans = 0;
        while(low < high){
            int curr = min(heights[low], heights[high]) * (high-low);
            ans = max(ans, curr);

            if(heights[low] > heights[high])high--;
            else low++;
        }

        return ans;
    }
};
