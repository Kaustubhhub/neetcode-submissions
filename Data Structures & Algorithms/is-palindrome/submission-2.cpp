class Solution {
public:
    bool isAlphaNumerical(char ch){
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start <= end){
            while((start <= end) && !isAlphaNumerical(s[start])){
                start++;
            }
            while((start <= end) && !isAlphaNumerical(s[end])){
                end--;
            }

            if((start <= end) && tolower(s[start]) != tolower(s[end]))return false;
            start++;
            end--;
        }

        return true;
    }
};
