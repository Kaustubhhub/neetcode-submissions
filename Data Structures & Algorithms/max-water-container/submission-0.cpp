class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start =0, end = heights.size()-1;
        int max_area = 0;
        while(start < end){
            int area = (end-start) * min(heights[start], heights[end]);
            max_area = max(max_area, area);
            if(heights[start] > heights[end]){
                end--;
            }else{
                start++;
            }
        }
        return max_area;
    }
};
