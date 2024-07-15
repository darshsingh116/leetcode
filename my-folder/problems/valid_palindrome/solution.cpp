class Solution {
public:
    bool isPalindrome(string s) {

        int i=0,j=s.length()-1;
        if(j<1){return true;}
        while(i!=j && i<j){
            char a,b;
            a=s[i];
            b=s[j];
            a=tolower(a);
            b=tolower(b);

            if(!(('a'<=a && a<='z') || ('0'<=a && a<='9'))){
                i++;
                continue;
            }
            if(!(('a'<=b && b<='z') || ('0'<=b && b<='9'))){
                j--;
                continue;
            }

            if(a != b){
                return false;
            }

            i++;
            j--;
        }
        return true;
    }
};