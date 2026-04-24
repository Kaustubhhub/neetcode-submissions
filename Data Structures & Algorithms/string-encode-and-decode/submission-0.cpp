class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto it : strs){
            ans += to_string(it.size()) + "#" + it;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;

        while(i<s.size()){
            int j = i;
            while(j < s.size() && s[j] != '#')j++;

            int length = stoi(s.substr(i,j-i));
            i = j+1;
            j = length +i;
            ans.push_back(s.substr(i,length));
            i = j;
        }

        return ans;
    }
};
