class Solution {
public:
    int firstOccurence(vector<int> nums, int key)
    {
        for(int i=0;i<nums.size();i++)
        {
            //cout<<"runs1"<<endl;
            if(nums[i]==key)
            {
                return i;
            }
        }
        return -1;
    }
    
    int lastOccurence(vector<int> nums, int key)
    {
        for(int i=nums.size()-1;i>=0;i--)
        {
            //cout<<"runs2  "<<nums[i]<<endl;
            if(nums[i]==key)
            {
                return i;
            }
        }
        return -1;
    }
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int,int> u;
        
        for(int i=0;i<nums.size();i++)
        {
            u[nums[i]]++;
        }
    
        int val=u[nums[0]];
        for(auto it:u)
        {
            if(it.second>val)
            {
                val=it.second;
            }
        }
        
        vector<int> freq;
        for(auto it:u)
        {
            if(it.second==val)
            freq.push_back(it.first);
        }
        
        int size=nums.size();
        for(int i=0;i<freq.size();i++)
        {
            //cout<<freq[i]<<endl;
            size=min(size,lastOccurence(nums,freq[i])-firstOccurence(nums,freq[i])+1);
        }
        return size;
        
        
    }
};