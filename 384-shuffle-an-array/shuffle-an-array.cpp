class Solution {
public:
    vector<int> curr;
    vector<int> dup;
    Solution(vector<int>& nums) {
        curr=nums;
        dup=nums;
    }
    
    vector<int> reset() {
        dup=curr;
        return dup;
    }
    
    vector<int> shuffle() {
        
        for(int i=1;i<dup.size();i++){
            int r=(rand()%(i+1));
            swap(dup[i],dup[r]);
        }
        return dup;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */