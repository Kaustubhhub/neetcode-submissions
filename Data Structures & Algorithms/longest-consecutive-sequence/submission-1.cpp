class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        int res = 1, counter = 1;
        unordered_set<int>s(nums.begin(), nums.end());
        vector<int>temp;
        for(auto it : s){
            temp.push_back(it);
        }
        sort(temp.begin(), temp.end());
        for(int num : nums){
            cout<<num<<" ";
        }
        for(int i=1; i<temp.size(); i++){
            if(temp[i]-1 == temp[i-1]){
                counter++;
                res = max(res, counter);
            }else{
                counter = 1;
            }
        }
        return res;
    }
};
