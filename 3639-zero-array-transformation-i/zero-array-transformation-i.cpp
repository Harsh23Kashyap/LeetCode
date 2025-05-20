class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int> u;

        for(auto it:queries){
            int st=it[0],end=it[1];
            u[st]++;
            u[end+1]--;
        }
        vector<int> ls(nums.size()+1,0);
        int c=0;
        for(int i=0;i<nums.size()+1;i++){
            if(u.find(i)!=u.end()){
                c+=u[i];
            }
            ls[i]=c;
        }
        for(auto it:ls)
        cout<<it<<" ";

        for(int i=0;i<nums.size();i++){
            if(nums[i]-ls[i]>0)
            return false;
        }
        return true;
    }
};