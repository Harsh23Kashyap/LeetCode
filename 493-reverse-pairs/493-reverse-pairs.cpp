class Solution {
public:
    
    int inverse(vector<int>& nums, int s, int e, int m)
    {
        int c=0;
        vector<int> temp;
        int i=s,j=m+1;
        while(i<=m and j<=e)
        {
            long long a=nums[i];
            long long b= nums[j];
            b*=2;
            if(a>b)
            {
                //cout<<nums[i]<<"at "<<i<<" , and "<<nums[j]<<" at "<<j<<endl;
                c+=(m-i+1);
                j++;
            }
            else
                i++;
        }
        i=s,j=m+1;
        while(i<=m and j<=e)
        {
            if(nums[i]>nums[j])
                temp.push_back(nums[j++]);
            else
                temp.push_back(nums[i++]);
        }
        
        while(i<=m)
            temp.push_back(nums[i++]);
        while(j<=e)
            temp.push_back(nums[j++]);
        
        int k=0;
        for(int i=s;i<=e;i++)
            nums[i]=temp[k++];
            
        //cout<<c<<endl;
        return c;
        
    }
    
    int merge(vector<int>& nums, int s, int e)
    {
        if(s>=e)
            return 0;
        int m=s+(e-s)/2;
        int x= merge(nums,s,m);
        int y=merge(nums,m+1,e);
        int z=inverse(nums,s,e,m);
        
        return x+y+z;
    }
              
              
              
    int reversePairs(vector<int>& nums) 
    {
        return merge(nums,0,nums.size()-1);
        
    }
};