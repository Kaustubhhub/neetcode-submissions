class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>count;
        vector<vector<int>> freq(n + 1);

        for(int num : nums){
            count[num]++;
        }

        for(auto it : count){
            freq[it.second].push_back(it.first);
        }
        vector<int>res;
        for(int i=n; i>=0; i--){
            for(int it : freq[i]){
                res.push_back(it);
                if(res.size() == k)return res;
            }
        }
        return res;
    }
};
