class Solution {
public:
string operation(string x, string y, string sign){
        if(sign == "+")return to_string(stoi(x) + stoi(y));
        else if(sign == "-")return to_string(stoi(x) - stoi(y));
        else if(sign == "*")return to_string(stoi(x) * stoi(y));
        else if(sign == "/")return to_string(stoi(x) / stoi(y));
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/"){
                string y = st.top(); st.pop();
                string x = st.top(); st.pop();
                string val = operation(x,y,tokens[i]);
                st.push(val);
            }else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};
