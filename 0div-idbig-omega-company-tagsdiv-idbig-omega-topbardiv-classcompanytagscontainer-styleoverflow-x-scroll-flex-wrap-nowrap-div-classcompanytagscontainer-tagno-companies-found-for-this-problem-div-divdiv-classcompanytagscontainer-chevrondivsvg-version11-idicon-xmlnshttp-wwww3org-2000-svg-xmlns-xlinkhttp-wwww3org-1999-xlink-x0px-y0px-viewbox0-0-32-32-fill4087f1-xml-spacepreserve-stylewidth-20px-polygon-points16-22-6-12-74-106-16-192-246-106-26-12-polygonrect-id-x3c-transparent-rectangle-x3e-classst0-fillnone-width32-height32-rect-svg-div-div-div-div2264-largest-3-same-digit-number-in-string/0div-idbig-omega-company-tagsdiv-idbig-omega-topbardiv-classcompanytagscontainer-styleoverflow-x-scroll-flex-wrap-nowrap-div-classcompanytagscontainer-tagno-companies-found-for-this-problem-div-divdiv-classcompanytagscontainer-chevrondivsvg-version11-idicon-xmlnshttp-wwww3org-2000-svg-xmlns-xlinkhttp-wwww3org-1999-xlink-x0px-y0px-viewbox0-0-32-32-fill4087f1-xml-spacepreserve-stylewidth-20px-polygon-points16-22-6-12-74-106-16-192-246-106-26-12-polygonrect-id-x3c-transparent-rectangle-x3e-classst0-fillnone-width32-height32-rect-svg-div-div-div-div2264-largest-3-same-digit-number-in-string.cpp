class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=0;i<=num.size()-3;i++)
        {
            if(num[i]==num[i+1] and num[i+1]==num[i+2])
            {
                if(ans=="" or ans[0]<num[i])
                    ans=num[i];
            }
            // cout<<ans<<endl;   
        }
        return ans+ans+ans;
    }
};