class Solution {
public:
    void combo(int i, vector<int> c,int t,   vector<vector<int>> &ans, vector<int> &temp)
    {
        if(t==0){
            ans.push_back(temp);
            return;
        }
        if(i==c.size()){
            return;
        }
        if(t-c[i]<0)
        return;
        temp.push_back(c[i]);
        // int j=i+1;
        // while(j<c.size() and c[j]==c[i]){
        //     j++;
        // }
        combo(i,c,t-c[i],ans,temp);
        temp.pop_back();
        combo(i+1,c,t,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        combo(0,candidates,target,ans,temp);
        return ans;
    }
};