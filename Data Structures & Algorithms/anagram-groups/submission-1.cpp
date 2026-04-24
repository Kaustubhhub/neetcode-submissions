class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;

        for(string str : strs){
            vector<int>freq(26,0);
            for(char ch : str){
                freq[ch -'a']++;
            }

            string key = to_string(freq[0]);
            for(int i=1; i<26; i++){
                key += ','+ freq[i];
            }

            mp[key].push_back(str);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
