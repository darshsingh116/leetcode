class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int pdt = 1;
        int nonzero = 1;
        int freqZero =0;
        for(int i=0; i<nums.size(); i++){
            pdt = pdt * nums[i];
            if(nums[i] == 0){
                freqZero++;
            }else{
                nonzero = nonzero * nums[i];
            }
        }
        //cout <<freqZero;

        for(int i=0; i<nums.size(); i++){
            cout << nums[i];
            if(nums[i] != 0 && pdt != 0){
                answer.insert(answer.end(),pdt/nums[i]);
                //cout<<"a";
            }else if(nums[i] != 0 && pdt == 0){
                //cout<<"b";
                 answer.insert(answer.end(),0);
            }else if(freqZero == 1){
                answer.insert(answer.end(),nonzero);
                //cout<<"c";
            }else{
                answer.insert(answer.end(),0);
            }
            
        }


        return answer;
    }
};