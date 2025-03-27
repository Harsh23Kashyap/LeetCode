class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        unordered_map<int,int> u;
        unordered_map<int,int> lu;
        for(auto it:nums)
        u[it]++;
        int lmaxi=nums[0];
        lu[nums[0]]++;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            u[curr]--;
            int lsz=i+1;
            int rsz=nums.size()-lsz;
            if(i!=0)
                lu[curr]++;

            lmaxi=(u[curr]>u[lmaxi]?curr:lmaxi);
            cout<<i<<" "<<lmaxi<<endl;
            int lfreq=lu[lmaxi];
            int rfreq=u[lmaxi];
            // cout<<"L Frequency - "<<lfreq<<" "<<rfreq<<endl;
            // cout<<lsz<<" "<<rsz<<endl;
            if(lfreq*2>lsz and rfreq*2>rsz)
                return i;

            


        }
        return -1;
    }
};