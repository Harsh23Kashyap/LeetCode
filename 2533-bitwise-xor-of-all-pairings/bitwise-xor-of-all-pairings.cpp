class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()%2==0 and nums2.size()%2==0)
        return 0;

        int x=0;
        int a=nums1.size()%2;
        if(a==1)
        {
            for(auto it:nums2)
                x=x^it;
        }
        // cout<<x<<endl;
        a=nums2.size()%2;
        if(a==1)
        {
            for(auto it:nums1)
                x=x^it;
        }
        return x;
    }
};

/*



*/