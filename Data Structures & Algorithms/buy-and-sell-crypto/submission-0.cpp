class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnn = prices[0];
        int mxx = 0;
        for(int i=0; i<prices.size(); i++){
            cout<<"i : "<<i<<"\n";
            if(prices[i] < mnn){
                mnn = prices[i];
            }
            mxx = max(mxx, prices[i]-mnn);
            cout<<"mnn : "<<mnn<<" mxx : "<<mxx<<"\n";
        }

        return mxx;
    }
};
