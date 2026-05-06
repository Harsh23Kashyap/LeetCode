class Solution {
    
public:
    class SegmentTree{

        public:
        vector<int> arr;
        vector<int> sgt;
        SegmentTree(int n, vector<int> nums){
            sgt.resize(4*n);
            arr=nums;
            build(0,0,n-1);
        }
        void build(int idx, int l, int r){
        if(l == r){
            sgt[idx] = arr[l];
            return;
        }

        int m = (l + r) / 2;
        build(2*idx+1, l, m);
        build(2*idx+2, m+1, r);

        sgt[idx] = max(sgt[2*idx+1] , sgt[2*idx+2]);
    }

    void update(int idx, int low, int high, int i, int val) {
        if (low == high) {
            sgt[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);

        sgt[idx] = max(sgt[2 * idx + 1], sgt[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int start, int end) 
    {
        if(start > high or end < low)
            return INT_MIN;

        if(low >= start and high <= end)
            return sgt[idx];

        int mid = (low + high) / 2;
        int left = query(2*idx+1, low, mid, start, end);
        int right = query(2*idx+2, mid+1, high, start, end);

        return max(left , right);
    }

};
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        SegmentTree sgt(nums.size(),nums);
        vector<int> ans;
        for(int i=0;i<nums.size()-k+1;i++)
        {
            ans.push_back(sgt.query(0,0,nums.size()-1,i,i+k-1));
        }
        return ans; 



    }
};