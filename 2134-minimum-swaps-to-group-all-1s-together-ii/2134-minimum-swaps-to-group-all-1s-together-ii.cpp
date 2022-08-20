class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int c=count(nums.begin(),nums.end(),1);
        int ones=0,maxi=0;
        for(int i=0;i<c;i++)
        {
        
            if(nums[i]==1)
                ones++;
        }
        //cout<<0<<" and "<<c-1<<endl;
         //cout<<ones<<endl;
        maxi=ones;
        for(int i=c;i<nums.size();i++)
        {
            //cout<<i-c+1<<" and "<<i<<endl;
            if(nums[i-c]==1)
                ones--;
            if(nums[i]==1)
                ones++;
             cout<<ones<<endl;
            maxi=max(maxi,ones);
        }
        int j=0;
        for(int i=nums.size()-c;i<nums.size();i++)
        {
            //cout<<i+1<<" and "<<j<<endl;
             
            if(nums[j++]==1)
                ones++;
            if(nums[i]==1)
                ones--;
            //cout<<ones<<endl;
             maxi=max(maxi,ones);
            
            
        }
        return c-maxi;
    }
};