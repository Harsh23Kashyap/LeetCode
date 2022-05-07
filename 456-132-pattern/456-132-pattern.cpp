class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> mini;
        int minim = INT_MAX;
        stack<int> s;
        for(int i=0 ; i<nums.size() ; i++)
        {
            minim = min(minim,nums[i]);
            mini.push_back(minim);
        }
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            while(!s.empty() && nums[s.top()]<=nums[i])
                s.pop();
            if(!s.empty() && nums[i]>mini[s.top()])
            {
                cout<<nums[i]<<" "<<mini[i];
                return true;
            }
            s.push(i);
        }
        return false;
    }
};