class Solution {
public:
    bool isPalindrome(string s) {
        string m;
        for(char& c:s){
            if(c <='Z' && c >='A') c = c -'A'+'a';
            if((c>='a' && c <='z')||(c>='0'&& c<='9')) m.push_back(c);
            
        }

        int l =0,r = m.size()-1;
        while(l<=r){
            if(m[l]!=m[r]) return false;
            l++;
            r--;
        }
        return true;
        
    }
};