class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi=0;
        int i=0,j=0;

        while(i<nums1.size() and j<nums2.size()){
            if(i>=j){
                j=i;
            }
            if(nums1[i]<=nums2[j]){
                maxi=max(j-i,maxi);
                j++;
            }
            else if(nums1[i]>nums2[j]){
                i++;
            }
        }
        return maxi;
    }
};