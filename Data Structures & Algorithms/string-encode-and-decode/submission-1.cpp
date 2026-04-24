class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string= "";
        for(string str : strs){
            encoded_string += to_string(str.size()) +'#'+str;
        }
        cout<<encoded_string<<"\n";
        return encoded_string;
    }

    vector<string> decode(string s) {
    vector<string> decoded;
    int i = 0;

    while (i < s.size()) {
        string num_str = "";

        // Read the number safely
        while (i < s.size() && s[i] != '#') {
            num_str += s[i];
            i++;
        }

        // Move past '#'
        i++;

        int len = stoi(num_str);
        string temp = "";

        // Extract exactly `len` characters
        for (int count = 0; count < len && i < s.size(); count++, i++) {
            temp += s[i];
        }

        decoded.push_back(temp);
    }

    return decoded;
}
};
