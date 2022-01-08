class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int> m(nums.size()-1,0);
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        
        //HOUSE 1 to n-1
        m[0]=nums[0];
        m[1]=nums[1];
        for(int i=2;i<nums.size()-1;i++)
        {
            cout<<"Running for "<<i<<endl;
            auto it=max_element(m.begin(),m.begin()+i-1);
            m[i]=m[i]+(*it)+nums[i];
        }
        auto maxi= max_element(m.begin(),m.end());
        int store= *maxi;
        cout<<"First - "<<store<<endl;
        
        //HOUSE 2 to n
        vector<int> n(nums.size()-1,0);
        n[0]=nums[1];
        n[1]=nums[2];
        for(int i=3;i<nums.size();i++)
        {
            cout<<"Running for "<<i<<endl;
            auto it=max_element(n.begin(),n.begin()+i-2);
            cout<<"Highest - "<<(*it);
            n[i-1]=n[i-1]+(*it)+nums[i];
        }
        maxi= max_element(n.begin(),n.end());
        cout<<"Second - "<<*maxi<<endl;
        store= max(*maxi,store);
        
        
        
        return store;
        
    }
};