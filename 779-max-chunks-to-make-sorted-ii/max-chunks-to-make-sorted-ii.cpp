class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> cp=arr;
        sort(cp.begin(),cp.end());
        
        long long csum=0;
        long long  asum=0;
        int chunk=0;
        for(int i=0;i<arr.size();i++)
        {
            csum+=cp[i],asum+=arr[i];
            if(csum==asum)
                chunk++;
        }
        return chunk;
        
    }
};