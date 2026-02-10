class Solution {
public:
    int divide(vector<int> &nums, int l, int r){
        int pivot=nums[r];

        int i=l;
        for(int j=l;j<r;j++){
            if(nums[j]<pivot){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
    int partition(vector<int> &nums, int l, int r, int k ){
         if(l == r) 
            return nums[l];
            int randomIndex = l + rand() % (r - l + 1);
            swap(nums[randomIndex], nums[r]);
            int p=divide(nums,l,r);

            if(p==k)
            return nums[p];
            else if(p<k)
                return partition(nums, p+1,r,k);
            else
                return partition(nums, l,p-1,k);

    }
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, 0,nums.size()-1,nums.size()-k);
    }
};