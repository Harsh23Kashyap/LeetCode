class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans;
        set<int> v1;
        set<int> v2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i:nums1)
        {
            bool found=false;
            for(int j:nums2 )
            {
                if(j>i)
                    break;
                if(i==j)
                {
                    found=true;
                    break;
                }
            }
            if(!found)
                v1.insert(i);
        }
         for(int i:nums2)
        {
            bool found=false;
            for(int j:nums1 )
            {
                if(j>i)
                    break;
                if(i==j)
                {
                    found=true;
                    break;
                }
            }
            if(!found)
                v2.insert(i);
        }
        vector<int> v11(v1.begin(), v1.end());
        ans.push_back(v11);
        vector<int> v22(v2.begin(), v2.end());
        ans.push_back(v22);
        return ans;
    }
    
    
};