class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int s=0;
        int c=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            if(i<k-1)
            continue;
            if(i>=k)
                s-=arr[i-k];
            
            if((s*1.0)/k>=threshold){
            c++;
            // cout<<i-k+1<<" "<<i<<" ->"<<s<<endl;
            }

        }
        return c;
    }
};