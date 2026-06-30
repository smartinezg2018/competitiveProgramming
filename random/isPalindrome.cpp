class Solution {
public:
    bool isPalindrome(string s) {
        string m;
        for(char& c:s){
            if(c <='Z' && c >='A') c = c -'A'+'a';
            if((c>='a' && c <='z')||(c>='0'&& c<='9')) m.push_back(c);
            
        }

        reverse(m.begin(),m.end());
        return m == s;
        
    }
};