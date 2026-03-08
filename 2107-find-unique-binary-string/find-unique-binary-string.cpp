class Solution {
public:
    vector<string> ans;
    void recur(string s, int i, int n){
        if(i==n){
            // cout<<s<<endl;
            ans.push_back(s);
            return;
        }

        recur(s+"0",i+1,n);
        recur(s+"1",i+1,n);
    }
    string findDifferentBinaryString(vector<string>& nums) {
         recur("", 0,nums[0].size());
        sort(nums.begin(),nums.end());
        
        int res=0;
        int i;
        for(i=0;i<nums.size();i++){
             if(ans[i]!=nums[i])
                return ans[i];
        }
        if(i<ans.size())
            return ans[i];
        return "";
    }
};