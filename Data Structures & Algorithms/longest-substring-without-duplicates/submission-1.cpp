class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int n = s.size();
        int l = 0, r = 0;
        unordered_set<char>ss;
        while(l<n && r<n){
            if(ss.find(s[r]) == ss.end()){
                ss.insert(s[r]);
                maxLength = max(maxLength, r-l+1);
                r++;
            }else{
                while(ss.find(s[r]) != ss.end()){
                    ss.erase(s[l]);
                    l++;
                }
            }
        }

        return maxLength;
    }
};
