class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char>charSet(s.begin(),s.end());

        for(char ch : charSet){
            int count =0, l=0;
            for(int r=0; r<s.size(); r++){
                if(s[r] == ch){
                    count++;
                }

                while((r-l+1) - count > k){
                    if(s[l] == ch){
                        count--;
                    }
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};
