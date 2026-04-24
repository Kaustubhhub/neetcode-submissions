class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n = nums.size();
        vector<int>res;
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                res.push_back(0);
                if(i>0 && nums[i] > nums[i-1]){
                st.push({nums[i],i});
            }
                continue;
            }
            while(!st.empty() && nums[i] >= st.top().first){
                st.pop();
            }
            if(st.empty()){
                res.push_back(0);
            }else{
                res.push_back(st.top().second-i);
            }

            if(i>0 && nums[i] > nums[i-1]){
                st.push({nums[i],i});
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
