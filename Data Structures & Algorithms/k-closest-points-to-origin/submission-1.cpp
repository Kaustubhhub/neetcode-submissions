class Solution {
   public:
    float calculate(int x, int y){
        return sqrt((x*x)+(y*y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        priority_queue<pair<float, pair<int,int>>> pq;

        for (auto it : points) {
            if(pq.size()<k){
                pq.push({calculate(it[0],it[1]),{it[0], it[1]}});
            }else{
                
                float d1 = calculate(it[0],it[1]);
                if(d1 < pq.top().first){
                    pq.pop();
                    pq.push({d1,{it[0], it[1]}});
                }
            }
        }

        while(!pq.empty()){
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return res;
    }
};
