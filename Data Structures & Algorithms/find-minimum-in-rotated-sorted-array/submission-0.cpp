class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int res = nums[0];

        while(r>=l){
            if(nums[l] < nums[r]){
                res = min(res, nums[l]);
                break;
            }
            int mid = l+(r-l)/2;
            res = min(nums[mid], res);
            if(nums[l] > nums[mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};
