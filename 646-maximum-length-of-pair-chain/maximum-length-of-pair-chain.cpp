class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        int maxi=1;
        int l=pairs[0][1];
        for(int i=1;i<n;i++){
            if(l<pairs[i][0]){
                maxi++;
                l=pairs[i][1];
            }
            else{
                l=min(l,pairs[i][1]);
            }

        }

        return maxi;
    }
};