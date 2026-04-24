class Solution {
public:
    bool isValidAnagram(string s, string t){
        if(s.size() != t.size())return false;
        vector<int>freq(26,0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(int val : freq){
            if(val !=0)return false;
        }

        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans;
        vector<int>visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                vector<string>temp;
                temp.push_back(strs[i]);
                visited[i] = 1;
                for(int j=i+1; j<n; j++){
                    bool flag = isValidAnagram(strs[i], strs[j]);
                    if(flag){
                        visited[j]=1;
                        temp.push_back(strs[j]);
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
