class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>mpp;

        for(int num : nums){
            mpp[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto it : mpp){
            if(pq.size() < k){
                pq.push({it.second, it.first});
            }else{
                auto node = pq.top();
                if(it.second > node.first){
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }

        while(!pq.empty()){
            auto node = pq.top();
            res.push_back(node.second);
            pq.pop();
        }

        return res;
    }
};
