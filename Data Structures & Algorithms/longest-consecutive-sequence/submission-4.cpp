class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());

        int maxLength = 0;

        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]-1) != s.end())continue;

            int currLength = 0;
            int currVal = nums[i];
            while(s.find(currVal) != s.end()){
                currLength++;
                currVal++;
                maxLength = max(maxLength, currLength);
            }
        }

        return maxLength;
    }
};
