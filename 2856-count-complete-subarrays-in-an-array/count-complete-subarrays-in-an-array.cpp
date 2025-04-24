class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> u;
            unordered_map<int ,int> uu;
        for(auto it:nums)
            u.insert(it);

        int c=u.size();
        cout<<c<<endl;
        int l=0,r=0;
        int tot=0;
        while(r<nums.size()){
            uu[nums[r]]++;
            // cout<<uu.size()<<" "<<nums[r]<<" "<<uu[nums[r]]<<endl;
            while(l<=r and uu.size()>=c){
                // cout<<"Found  at "<<l<<" "<<r<<endl;
                tot+=(nums.size()-r);
                int ch=nums[l];
                uu[ch]--;
                if(uu[ch]==0)
                    uu.erase(ch);
                l++;
                
            }
            r++;
        }
        return tot==0?1:tot;
    }
};