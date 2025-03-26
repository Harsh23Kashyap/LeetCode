class Solution {
public:
    int pass(vector<int> res,int k, int m){
        int ans=0;
        for(auto it:res){
            if(abs(it-m)%k==0){
                ans+=abs(it-m)/k;
            }
            else return -1;
        }
        return ans;
    }
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> ans;
        int sum=0;
        for(auto it:grid){
            for(auto j:it)
                ans.push_back(j);
        }   
        sort(ans.begin(),ans.end());
        // return -1;
        int sz=ans.size();
        if(sz%2==0){
            int a=pass(ans,x,ans[sz/2]);
            int b=pass(ans,x,ans[(sz/2)-1]);
            if(a==-1)
            return b;
            else if (b==-1)
            return a;
            else
            return min(a,b);
        }

        return pass(ans,x,ans[sz/2]);
    }
};