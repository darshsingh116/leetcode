class Solution {
public:

    string tillhun(int num, unordered_map<int,string>& words){
        cout<<num<<endl;
        if(num==0){return "";}
        string ans="";
        int temp;
        temp=num%(100);
        if(temp<=20){
            ans=words[temp];
        }else{
            if(temp%10==0){ans=words[temp];}
            else{
                ans=words[temp-(temp%10)]+" "+words[temp%10];
            }
        }
        num /=100;

        if(num==0){return ans;}

        temp=num%10;
        if(temp!=0){
            if(ans==""){
                ans= words[temp]+" "+words[100];
            }else{
                ans= words[temp]+" "+words[100]+" "+ans;
            }
           
        }

        return ans;
    }
    string numberToWords(int nums) {
        int num=nums;
        unordered_map<int,string> words;
        // words[0]="Zero";
        words[1]="One";
        words[2]="Two";
        words[3]="Three";
        words[4]="Four";
        words[5]="Five";
        words[6]="Six";
        words[7]="Seven";
        words[8]="Eight";
        words[9]="Nine";
        words[10]="Ten";
        words[11]="Eleven";
        words[12]="Twelve";
        words[13]="Thirteen";
        words[14]="Fourteen";
        words[15]="Fifteen";
        words[16]="Sixteen";
        words[17]="Seventeen";
        words[18]="Eighteen";
        words[19]="Nineteen";
        words[20]="Twenty";
        words[30]="Thirty";
        words[40]="Forty";
        words[50]="Fifty";
        words[60]="Sixty";
        words[70]="Seventy";
        words[80]="Eighty";
        words[90]="Ninety";
        words[100]="Hundred";
        words[1000]="Thousand";
        words[1000000]="Million";
        words[1000000000]="Billion";

        if(num==0){return "Zero";}

        string ans="";

        
        if(num%1000!=0){
            ans = tillhun(num%1000,words);
        }
        num -= (num%1000);
        num /=1000;
        if(num==0){return ans;}

        if(num%1000!=0){
            if(ans==""){
                ans = tillhun(num%1000,words)+" "+words[1000];
            }else{
                ans = tillhun(num%1000,words)+" "+words[1000]+" "+ans;
            }
        }
        num -= (num%1000);
        num /=1000;
        if(num==0){return ans;}

        if(num%1000!=0){
            if(ans==""){
                ans = tillhun(num%1000,words)+" "+words[1000000];
            }else{
                ans = tillhun(num%1000,words)+" "+words[1000000]+" "+ans;
            }
        }
        num -= (num%1000);
        num /=1000;
        if(num==0){return ans;}

       if(num%1000!=0){
            if(ans==""){
                ans = tillhun(num%1000,words)+" "+words[1000000000];
            }else{
                ans = tillhun(num%1000,words)+" "+words[1000000000]+" "+ans;
            }
        }
        return ans;
        



        



        



    }
};