class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";

        for(string str : strs){
            encodedString += to_string(str.size()) + "#" + str;
        }

        cout<<"encoded : "<<encodedString<<"\n";
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string>encoded;

        int index = 0;
        while(index < s.size()){
        string currLength = "";
            while(s[index] != '#' && index < s.size()){
                currLength += s[index];
                index++;
            }
            index = index +1;
            string str = s.substr(index, stoi(currLength));
            encoded.push_back(str);
            index = index + stoi(currLength);
        }

        return encoded;
    }
};
