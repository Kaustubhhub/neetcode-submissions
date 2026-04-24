class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest_str = 0;
        int l = 0, max_freq = 0;
        unordered_map<char,int>count;

        for(int i=0; i<s.size(); i++){
            count[s[i]]++;
            max_freq = max(max_freq, count[s[i]]);

            while((i-l+1)-max_freq > k){
                count[s[l]]--;
                l++;
            } 

            longest_str = max(longest_str, i-l+1);
        }

        return longest_str;
    }
};
