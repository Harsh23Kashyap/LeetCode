class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int l=0,r=0;
        int maxi=0;
        while(r<nums.size()){
            m.insert(nums[r]);
            // cout<<"best "<<*m.begin()<<" "<<*m.rbegin()<<endl;
            while(l<r and abs(*m.begin()-*m.rbegin())>limit){
m.erase(m.find(nums[l]));                    
l++;
                }
            maxi=max(maxi,r-l+1);
            // cout<<l<<" "<<r<<endl;
            r++;
        }
        return maxi;
    }
};