class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>count1;
        for(char ch : s1){
            count1[ch]++;
        }
        int need = count1.size();
        for(int i=0; i<s2.size(); i++){
            int cnt = 0;
            unordered_map<char,int>count2;
            for(int j=i; j<s2.size(); j++){
                count2[s2[j]]++;
                if(count2[s2[j]] > count1[s2[j]]){
                    break;
                }

                if(count2[s2[j]] == count1[s2[j]]){
                    cnt++;
                }

                if(cnt == need)return true;
            }
        }
        return false;
    }
};
