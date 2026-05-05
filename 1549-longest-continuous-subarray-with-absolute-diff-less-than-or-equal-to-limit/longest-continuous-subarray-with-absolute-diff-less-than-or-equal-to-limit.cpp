class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxi,mini;
        int l=0,r=0;
        int ans=1;
        while(r<nums.size()){
            while(!maxi.empty() and nums[maxi.back()]<=nums[r])
                maxi.pop_back();
            
            while(!mini.empty() and nums[mini.back()]>=nums[r])
                mini.pop_back();

            maxi.push_back(r);
            mini.push_back(r);
            while(l<=r and nums[maxi.front()]-nums[mini.front()]>limit)
            {
                if(maxi.front()==l)
                    maxi.pop_front();
                
                if(mini.front()==l)
                    mini.pop_front();
                
                l++;
                
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};