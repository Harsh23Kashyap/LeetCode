class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=dimensions[0][0]*dimensions[0][1];
        double maxi=dimensions[0][0]*dimensions[0][0]+dimensions[0][1]*dimensions[0][1];

        for(auto it:dimensions){
            double check= it[0]*it[0]+it[1]*it[1];
            if(check>maxi)
            {
                maxi=check;
                ans= it[0]*it[1];
            }
            else if(check==maxi)
            {
                maxi=check;
                ans= max(ans,it[0]*it[1]);
            }
          

        }
        return ans;
    }
};