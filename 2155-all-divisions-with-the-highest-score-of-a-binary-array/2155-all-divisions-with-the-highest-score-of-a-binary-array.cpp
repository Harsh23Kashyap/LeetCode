class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) 
    {
        int count=accumulate(nums.begin(),nums.end(),0);
        vector<int> store(nums.size()+1,0);
        int track=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                store[i]=count;
                if(nums[i]==1)
                    track++;
            }
            else
            {
                store[i]=(i-track)+(count-track);
                if(nums[i]==1)
                    track++;
            }
        }
        store[nums.size()]=nums.size()-count;
        
        int maxi=*max_element(store.begin(),store.end());
        vector<int> ans;
        for(int i=0;i<store.size();i++)
        {
            //cout<<i<<" - "<<store[i]<<endl;
            if(store[i]==maxi)
                ans.push_back(i);
        }
        return ans;
        
    }
};