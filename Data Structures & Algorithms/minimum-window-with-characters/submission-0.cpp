class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>countT, window;
        for(char ch : t)countT[ch]++;
        pair<int,int>res = {-1,-1};
        int resSize = INT_MAX;
        int l = 0, need = countT.size(), count = 0;

        for(int r=0; r<s.size(); r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                count++;
            }

            while(need == count){
                char lc = s[l];
                if(resSize > (r-l+1)){
                    resSize = r-l+1;
                    res = {l,r};
                }
                window[lc]--;
                if(countT.count(lc) && window[lc] < countT[lc]){
                    count--;
                }
                l++;
            }
        }
        return resSize == INT_MAX? "" : s.substr(res.first,resSize );
    }
};
