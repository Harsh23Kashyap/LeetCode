class Solution {
public:
    
    int beautySum(string s) 
    {
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            unordered_map<char,int> u;
            for(int j=i;j<s.length();j++)
            {
                u[s[j]]++;
                int lower=INT_MAX,upper=INT_MIN;
                for(auto itr: u)
                 {
                      lower=min(lower,itr.second);
                      upper=max(upper,itr.second);
                  }
                 sum+=(upper-lower);
            }
                  
                
        
        }
        return sum;    
        
    }
};