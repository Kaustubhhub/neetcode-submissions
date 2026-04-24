class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>final;
        for(int n : nums1)final.push_back(n);
        for(int n : nums2)final.push_back(n);
        sort(final.begin(),final.end());
        int final_size = final.size();
        double ans;
        if(final_size & 1){
            int mid = final_size /2;
            return double(final[mid]);
        }
            int mid1 = final_size /2;
            int mid2 = mid1 - 1;
            ans = (final[mid1]+ final[mid2])/2.0;
            return ans;
    }
};
