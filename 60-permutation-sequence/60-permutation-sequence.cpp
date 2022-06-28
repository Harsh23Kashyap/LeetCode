class Solution {
public:
    string getPermutation(int n, int k) 
    {
        int fact=1;
        string ans="";
        vector<int> no;
        for(int i=1;i<=n;i++)
        {
            fact=fact*i;
            no.push_back(i);
        }
        fact/=n;
        k--;
        while(true)
        {
            ans+=to_string(no[k/fact]);
            no.erase(no.begin()+(k/fact));
            if(no.size()==0)
                break;
            k=k%fact;
            fact=fact/no.size();      
                

        }
        return ans;
        
    }
};