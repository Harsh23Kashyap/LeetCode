class Solution {
public:
vector<int> orig;
vector<int> backup;

    Solution(vector<int>& nums) {
        orig=nums;
        backup=nums;
    }
    
    vector<int> reset() {
        orig=backup;
        return orig;
    }
    
    vector<int> shuffle() {
        
        for(int i=0;i<orig.size()-1;i++){
            int rem=orig.size()-i;
            int k=rand()%rem;
            swap(orig[i],orig[i+k]);
        }
        return orig;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */