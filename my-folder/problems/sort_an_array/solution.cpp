class Solution {
public:
    void mearge(vector<int>& v,int start,int mid,int end){
        int i=0,j=mid+1-start,x=start;
        int size = end-start+1;
        vector<int> cp(size);

        for(int k=0;k<size;k++){
            cp[k]=v[start+k];
        }
      
        while(i<=(mid-start) && j<=(end-start)){
            if(cp[i]<=cp[j]){
                v[x++]=cp[i++];
            }else{
                v[x++]=cp[j++];
            }
        }
        if(i>(mid-start)){
            while(j<=(end-start)){
                v[x++]=cp[j++];
            }       
        }else{
            while(i<=(mid-start)){
                v[x++]=cp[i++];
            }
        }

    }
   
    void meargesort(vector<int>& v,int start,int end){
        if(start==end){
            return;
        }
        int mid=(start+end)/2;
        meargesort(v,start,mid);
        meargesort(v,mid+1,end);

        mearge(v,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        meargesort(nums,0,nums.size()-1);
        return nums;
    }
};



///////////////////////////////

