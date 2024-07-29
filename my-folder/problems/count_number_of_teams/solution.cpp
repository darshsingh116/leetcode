class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<int> dpasc(n,0);
        vector<int> dpdsc(n,0);

        for(int i=1;i<n;i++){
            for(int j=i;j<n;j++){
                if(rating[i]<rating[j]){
                    dpasc[i]++;
                }else if(rating[i]>rating[j]){
                    dpdsc[i]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i;j<n-1;j++){
                if(rating[i]<rating[j]){
                    ans+=dpasc[j];
                }else if(rating[i]>rating[j]){
                    ans+=dpdsc[j];
                }
            }
        }

        return ans;
    }
};

// (1 2 3 4 5)

// (2 3 5)   (1 4)

// (5 2)     (3)   (4)   (1)

// (2)   (5)
//  0,0      0,0