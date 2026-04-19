class NumArray {
public:
vector<int> arr;
vector<int> sgt;
int n=0;
    void build(int idx, int l, int r){
        if(l==r){
             sgt[idx]=arr[l];
             return;
        }

        int m=l+(r-l)/2;
        build(2*idx+1,l,m);
         build(2*idx+2,m+1,r);

        sgt[idx]=sgt[2*idx+1]+sgt[2*idx+2];
    }
    void updateOur(int idx, int low, int high, int i, int val) {
        if (low == high) {
            sgt[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            updateOur(2 * idx + 1, low, mid, i, val);
        else
            updateOur(2 * idx + 2, mid + 1, high, i, val);

        sgt[idx] = (sgt[2 * idx + 1]+ sgt[2 * idx + 2]);
    }

    
    int query(int idx, int low, int high, int start, int end) {
        if(start>high or end<low)
            return 0;

if(low >= start && high <= end)      
     return sgt[idx];

        int mid=low+(high-low)/2;
        int left=query(2*idx+1,low,mid,start,end);
        int right=query(2*idx+2,mid+1,high,start,end);
        return left+right;
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        sgt.resize(4*n);
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        updateOur(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
            return query(0,0,n-1,left,right);
    }   
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */