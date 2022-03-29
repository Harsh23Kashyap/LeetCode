class Solution {
public:
    bool self(int a)
    {
        int k=a;
        while(a)
        {
            int dig=a%10;
            if(dig==0 or k%dig!=0)
                return false;
            a/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int> ans;
        for(int i=left;i<=right;i++)
        {
            if(self(i))
                ans.push_back(i);
        }
        return ans;
        
    }
};