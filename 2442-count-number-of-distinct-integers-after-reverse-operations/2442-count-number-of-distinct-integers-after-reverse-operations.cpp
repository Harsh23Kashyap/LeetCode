class Solution {
public:
    int palindrome(int x)
    {
        int cx=x;
        int dig=0;
        while(x>0)
        {
            dig=dig*10+x%10;;
            x/=10;
        }
        //cout<<dig<<" - "<<cx<<endl;
        return dig;
    }
    int countDistinctIntegers(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(),nums.end());
         unordered_set<int> copy(nums.begin(),nums.end());
        //int n=s.size();
        for(auto it:s)
        {
            int k=palindrome(it);
            if(k!=it)
                copy.insert(k);
        }
        return copy.size();
        
    }
};