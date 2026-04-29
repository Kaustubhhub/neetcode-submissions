class Solution {
   public:
    bool isAlphanumeric(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }

        return false;
    }
    bool isPalindrome(string s) {
        int low = 0, high = s.size()-1;
cout<<"size : "<<s.size()<<'\n';
        while(high >= low){
            while(high >= low && !isAlphanumeric(s[low])){
                low++;
            }
            while(high >= low && !isAlphanumeric(s[high])){
                high--;
            }

            if(tolower(s[low]) != tolower(s[high])){
                cout<<low<<"\n"<<high<<"\n";
                return false;
                };
            high--;
            low++;
        }

        return true;
    }
};
