class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int> ps;
        int sum=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ps.push_back(sum);
            maxi=maxi+i*nums[i];
        }
        sum=maxi;
        // cout<<"CUrrent Sum is "<<maxi<<" "<<sum<<endl;
        for(int k=nums.size()-1;k>=0;k--){
            //So every element increases by the total sum, and the last element only reduces 
            //new sum is
           //divide two parts
           //left
           //any element apart from k so k-1
        //    cout<<"Avoiding "<<nums[k]<<endl;
           int nsum=0;
           if(k-1>=0)
           nsum+=ps[k-1];

           //right part k+1 to end.so endtill k
           if(k+1<ps.size())
            nsum+=ps.back()-ps[k];

            //now this is our good part;
            // .. and since we rotate it, its value will increasel

            nsum+=sum;
            // cout<<"Total nsum "<<nsum<<endl;

            //however, we have to neglect the kth value, so we need to reduce whatever it contributed last// which is basically, size*that
            nsum-=(nums[k]*(nums.size()-1));

            // cout<<nsum<<endl;

            maxi=max(maxi,nsum);
            sum=nsum;
        
        }
        return maxi;
        
    }
};