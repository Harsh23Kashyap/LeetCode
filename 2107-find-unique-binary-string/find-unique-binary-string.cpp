class Solution {
public:
string ans="";
bool pass(string res, int i,int len,unordered_set<string> u){
    if(u.find(res)==u.end()){
        // cout<<res<<" works"<<endl;
        ans=res;
        return true;
    }
    if(i==len)
        return false;

    //modify current
    bool check=pass(res,i+1,len,u);
    res[i]='1';
    check=check&pass(res,i+1,len,u);
    return check;

}
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_set<string> u(nums.begin(),nums.end());

        string res(nums[0].size(),'0');
        cout<<res<<endl;
        pass(res,0,nums[0].size(),u);
        return ans;
    }
};