class Solution {
public:
    string ans="";
    void recur(int n, unordered_set<string> a, string s)
    {
        if(s.size()==n)
        {
            if(a.find(s)==a.end())
            {
                ans=s;
                
            }
            return ;
        }
        if(ans!="")
            return;
        recur(n,a,s+"1");
        if(ans!="")
            return;
        recur(n,a,s+"0");
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
unordered_set<string> a(nums.begin(),nums.end());
        
        recur(nums.size(),a,"");
            return ans;
    }
};
