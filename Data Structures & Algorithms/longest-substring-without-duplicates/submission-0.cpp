class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r=0, l=0;
        int res = 0;

        unordered_map<char, int>mp;

        while(r<s.size()){
            mp[s[r]]++;
            if(mp[s[r]] > 1){
                while(mp[s[r]] != 1){
                    mp[s[l]]--;
                    l++;
                }
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
