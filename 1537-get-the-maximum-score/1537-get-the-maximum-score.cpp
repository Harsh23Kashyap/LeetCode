class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int i=0,j=0;
        long s1=0,s2=0,sum=0;
        
        while(i<nums1.size() and j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                s1+=nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                s2+=nums2[j];
                j++;
            }
            else
            {
                sum+=max(s1,s2)+nums1[i];
                i++;
                j++;
                s1=s2=0;
            }
                
        }
        while(i<nums1.size())
        {
            s1+=nums1[i];
            i++;
        }
        while(j<nums2.size())
        {
            s2+=nums2[j];
                j++;
        }
        
        sum+=max(s1,s2);
        return sum%1000000007;
    }
};