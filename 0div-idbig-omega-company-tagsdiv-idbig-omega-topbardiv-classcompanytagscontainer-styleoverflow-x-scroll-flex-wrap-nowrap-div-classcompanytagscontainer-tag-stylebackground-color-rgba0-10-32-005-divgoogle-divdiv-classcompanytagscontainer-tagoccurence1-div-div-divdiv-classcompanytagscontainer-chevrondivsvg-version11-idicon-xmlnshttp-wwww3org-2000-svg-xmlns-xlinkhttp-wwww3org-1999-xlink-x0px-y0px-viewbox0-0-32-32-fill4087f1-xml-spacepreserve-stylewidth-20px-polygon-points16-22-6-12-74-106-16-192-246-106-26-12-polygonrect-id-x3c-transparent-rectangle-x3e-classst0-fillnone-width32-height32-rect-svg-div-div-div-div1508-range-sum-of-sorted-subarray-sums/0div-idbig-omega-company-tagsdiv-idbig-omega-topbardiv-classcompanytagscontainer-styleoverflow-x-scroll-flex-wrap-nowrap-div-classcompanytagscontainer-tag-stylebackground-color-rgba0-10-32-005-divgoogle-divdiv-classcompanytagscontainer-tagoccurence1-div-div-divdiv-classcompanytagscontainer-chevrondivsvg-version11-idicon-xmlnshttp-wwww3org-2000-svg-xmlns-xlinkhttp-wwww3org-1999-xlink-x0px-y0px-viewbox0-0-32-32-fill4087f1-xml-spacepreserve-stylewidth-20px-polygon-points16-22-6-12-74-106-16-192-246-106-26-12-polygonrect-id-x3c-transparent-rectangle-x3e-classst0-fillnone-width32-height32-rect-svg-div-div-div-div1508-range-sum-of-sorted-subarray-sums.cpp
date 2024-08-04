class Solution {
public:
    int m=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> a;
        
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum=(sum+nums[j])%m;
                // cout<<sum<<endl;
                a.push_back(sum);
            }
        }
        sort(a.begin(),a.end());
        // for(int i:a)
        // {
        //     cout<<i<<endl;
        // }
        int sum=0;
        for(int i=left-1;i<=right-1;i++)
        {
            sum=(sum+a[i])%m;
        }
        return sum%m;
    }
};